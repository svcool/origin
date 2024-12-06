#include "httpserver.h"
#include <thread>
#include <bd.h>
#include <parserini.h>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP
#include <cstdlib> // Для system()

#pragma execution_character_set("utf-8")

int main() {
	// Установка кодировки консоли на UTF-8
	//setlocale(LC_ALL, "Russian");
	system("chcp 65001");
	//SetConsoleCP(CP_UTF8);
	//SetConsoleOutputCP(CP_UTF8);

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
		manage_db db("dbwords", dbConfig);

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

		std::string urlServer = "http://localhost:" + std::to_string(portCrowler);//для Windows
		std::string command = "start " + urlServer; // Для Windows
		system(command.c_str());

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
	return 0;
}