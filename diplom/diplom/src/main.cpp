#include "httpserver.h"
#include <safequeue.h>
#include <indexator.h>
#include <httpclient.h>
#include <tempfile.h>
#include <thread>
#include <future>
#include <mutex>
#include <bd.h>
#include <parserini.h>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP

//#pragma execution_character_set("utf-8")

// Глобальные мьютексы для защиты функций
std::mutex http_mutex;
std::mutex clean_mutex;
std::mutex extract_mutex;
std::mutex count_mutex;

std::string lastpage;

void worker(Safe_queue& sq, int maxDeep, manage_db& db) {
	std::thread::id this_id = std::this_thread::get_id(); // Получаем идентификатор текущего потока
	std::cout << "Старт парсинга сайтов. ID" << this_id << std::endl;

	while (true) {
		UrlDeep queueUrlDeep;// структура из url и глубины deep
		
				queueUrlDeep = sq.popFront(); //безопасная очередь
		
				if (!queueUrlDeep.url.empty()) lastpage = queueUrlDeep.url; //сохраняем последнюю страницу

		if (queueUrlDeep.url.empty() || queueUrlDeep.deep > maxDeep) {
			std::cout << "Выход из обработчика сайтов." << std::endl;
			break;
		}
		try {

			std::string portWeb = "443";
		/*	std::string prefix = "http://";
			std::string checkUrl = queueUrlDeep.url.substr(0, 7);
			if (checkUrl == prefix)  {
				portWeb = "80";
			}*/
			auto [host, target] = fixURL(queueUrlDeep.url);            // Вызов функции для парсинга URL
			
			std::string parserHtml;// Блокируем доступ к http_get
			{
				std::lock_guard<std::mutex> lock(http_mutex);
				std::cout << "Парсинг сайта. ID" << this_id << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(5));
				parserHtml = httpGet(host, portWeb, target, 11);

				TmpFile tempFile("./tmp");
				if (parserHtml != "") tempFile.writeToFile(parserHtml);
				std::cout << "Имя временного файла: " << tempFile.getUniqueName() << std::endl;
				tempFile.closeFile();
			}
			std::string cleaned_text;
			{
				std::lock_guard<std::mutex> lock(clean_mutex);// Блокируем доступ к очистке и обработке текста
				std::cout << "Очистка текста. ID" << this_id << std::endl;
				if (parserHtml != "") cleaned_text = clean_and_process_text(parserHtml);

				TmpFile tempFile("./tmp/cleantext");
				tempFile.writeToFile(cleaned_text);
				std::cout << "Имя временного файла: " << tempFile.getUniqueName() << std::endl;
				tempFile.closeFile();
			}
			std::vector<std::string> links;
			{
				std::lock_guard<std::mutex> lock(extract_mutex);// Блокируем доступ к извлечению ссылок
				std::cout << "Извлечение ссылок. ID" << this_id << std::endl;
				if (parserHtml != "") links = extractLinks(parserHtml, host);
			}
			std::map<std::string, int> word_freq;
			{
				std::lock_guard<std::mutex> lock(count_mutex);// Блокируем доступ к подсчету частоты слов
				std::cout << "Подсчет частоты строк.ID" << this_id << std::endl;
				word_freq = countWordFrequency(cleaned_text);

				db.addDataTable("Document", "title", queueUrlDeep.url); // Добавляем документ
				for (const auto& [word, frequency] : word_freq) {
					db.addDataTable("Word", "name", word);

					//  Получаем ID документа и ID слова (это нужно реализовать)
					int documentId = db.select("Document", "title", queueUrlDeep.url); // Выполняем выборку
					int wordId = db.select("Word", "name", word); 
					if (documentId == -1 || wordId == -1) continue;
					db.addWordDocuments("Document_Word", documentId, wordId, frequency);// Добавляем частоту слов
				}

			}
			  for (const auto& link : links) {
					auto linkDeep = queueUrlDeep.deep + 1;
					sq.push({ link, linkDeep }); // Увеличиваем глубину на 1
				}

		}
		catch (const std::exception& e) {
			std::cerr << "Исключение worker: " << e.what() << std::endl;
		}
	}
	
}

int main() {
	// Установка кодировки консоли на UTF-8
	setlocale(LC_ALL, "Russian");
	//system("chcp 65001");
SetConsoleCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);

	try {

		boost::property_tree::ptree pt;
		const std::string filename = "settings.ini";

		// Список необходимых ключей ini файла
		std::vector<std::string> requiredKeys = {
			"Database.host",
			"Database.port",
			"Database.dbname",
			"Database.user",
			"Database.password",
			"Spider.page",
			"Spider.recursion",
			"Crowler.address",
			"Crowler.port"
		};

		readSettings(filename, pt); // Чтение из INI файла

		checkRequiredKeys(pt, requiredKeys); // Проверка наличия всех необходимых ключей

		// Иницилизация значений из секции Database
		DbConfig dbConfig = {
		pt.get<std::string>("Database.host"), // dbHost
		pt.get<int>("Database.port"),        // port
		pt.get<std::string>("Database.dbname"), // dbName
		pt.get<std::string>("Database.user"),      // username
		pt.get<std::string>("Database.password"),   // password
		};
		std::cout << "Database Host: " << dbConfig.dbHost << std::endl;
		std::cout << "Database Port: " << dbConfig.port << std::endl;
		std::cout << "Database DB Name: " << dbConfig.dbName << std::endl;
		std::cout << "Database Username: " << dbConfig.username << std::endl;
		std::cout << "Database Username: " << dbConfig.password << std::endl;

		// Значения из секции Spider
		std::string page = pt.get<std::string>("Spider.page");
		int recursion = pt.get<int>("Spider.recursion");
		std::cout << "Page: " << page << std::endl;
		std::cout << "Recursion: " << recursion << std::endl;

		// Значения из секции Crowler
		std::string addressCrowler = pt.get<std::string>("Crowler.address");
		int portCrowler = pt.get<int>("Crowler.port");
		std::cout << "Crowler Address: " << addressCrowler << std::endl;
		std::cout << "Crowler Port: " << portCrowler << std::endl;

		//создаем базу данных
		clientdb r("dbwords", dbConfig);
		manage_db db("dbwords", dbConfig);

		//создаем таблицы клиентов и телефонов
		db.createTable("word", "document", "document_word");

		std::cout << "Page: " << page << std::endl;
	
		Safe_queue sq;
		sq.push({ page, 1 }); // Начальная глубина 1

		int num_threads = std::thread::hardware_concurrency();
		std::cout << "Количество ядер: " << num_threads << std::endl;

		net::io_context ioc{ 1 };
		tcp::acceptor acceptor{ ioc, {net::ip::make_address(addressCrowler), static_cast<unsigned short>(portCrowler)} };
		tcp::socket socket{ ioc };
		// Запуск HTTP сервера в отдельном потоке
		std::thread server_thread([&]() {
			http_server(acceptor, socket, db);
			ioc.run();
			});
		//Открытие поисковика
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::string relativePath = "index.html"; // файл находится в корне проекта
		std::string urlServer = "http://localhost:" + portCrowler + relativePath;//для Windows
		std::string command = "start " + relativePath; // Для Windows
		system(command.c_str());

		std::vector<std::thread> threads;
		for (int i = 0; i < num_threads - 2; ++i) {
			threads.emplace_back(worker, std::ref(sq), recursion, std::ref(db));
		}

		for (auto& t : threads) {// Ждем завершения всех потоков
			if (t.joinable()) {
				t.join();
			}
		}
		std::cout << "Все потоки Паука завершились" << std::endl;

		// Запись последнего сайта в INI файл
		pt.put("Spider.page", lastpage); // Обновление версии
		writeSettings(filename, pt);
		std::cout << "Последняя страница" << lastpage << std::endl;

		server_thread.join();  // Ожидаем завершения потока сервера
	}
	catch (const boost::property_tree::ini_parser::ini_parser_error& e) {
		std::cerr << "Error reading or writing INI file: " << e.what() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Ошибка:" << e.what() << std::endl;
		return EXIT_FAILURE;
	}

}