//#include "httpserver.cpp"
#include <safequeue.h>
#include <indexator.h>
#include <httpclient.h>
#include <tempfile.h>
#include <thread>
#include <future>
#include <mutex>
#include <bd.h>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP


#pragma execution_character_set("utf-8")
// Глобальные мьютексы для защиты функций
std::mutex http_mutex;
std::mutex clean_mutex;
std::mutex extract_mutex;
std::mutex count_mutex;

std::pair<std::string, std::string> parseUrl(const std::string& url) {

    std::string host;
    std::string target;
    std::string cleanUrl = std::regex_replace(url, std::regex(R"(^https?://)"), "");  // Удаляем протокол (http:// или https://)
    size_t pos = cleanUrl.find("/");// Находим позицию первого символа '/' после базового URL
    if (pos == std::string::npos) { // Если '/' не найден, значит, весь URL - это хост
        host = cleanUrl;
        target = "/";
    }
    else {
        // Извлекаем базовый URL и путь
        host = cleanUrl.substr(0, pos); // Извлекаем базовый URL и путь
        target = cleanUrl.substr(pos);   // Путь
    }
    return std::make_pair(host, target);
}
void worker(Safe_queue& sq, int maxDeep, manage_db& db) {
    std::thread::id this_id = std::this_thread::get_id(); // Получаем идентификатор текущего потока
    std::cout << "Worker started. ID" << this_id << std::endl;

    while (true) {
        UrlDeep urlDeep;
        urlDeep = sq.popFront(); //безопасная очередь
        
            if (urlDeep.url.empty() || urlDeep.deep > maxDeep) {
                std::cout << "Worker exiting due to empty URL." << std::endl;
                break;
            }
            try {
            auto [host, target] = parseUrl(urlDeep.url);            // Вызов функции для парсинга URL
            std::string parserHtml;// Блокируем доступ к http_get
            {
                std::lock_guard<std::mutex> lock(http_mutex);
                std::cout << "Worker parserHtml. ID" << this_id << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
                parserHtml = http_get(host, "80", target, 11);
               
                TmpFile tempFile("./tmp");
                tempFile.writeToFile(parserHtml);
                std::cout << "Имя временного файла: " << tempFile.getUniqueName() << std::endl;
                tempFile.closeFile();
            }          
            std::string cleaned_text;
            {
                std::lock_guard<std::mutex> lock(clean_mutex);// Блокируем доступ к очистке и обработке текста
                std::cout << "Worker cleaned_text. ID" << this_id << std::endl;
                cleaned_text = clean_and_process_text(parserHtml);

                TmpFile tempFile("./tmp/cleantext");
                tempFile.writeToFile(cleaned_text);
                std::cout << "Имя временного файла: " << tempFile.getUniqueName() << std::endl;
                tempFile.closeFile();
            }
            std::vector<std::string> links;
            {
                std::lock_guard<std::mutex> lock(extract_mutex);// Блокируем доступ к извлечению ссылок
                std::cout << "Worker extractLinks. ID" << this_id << std::endl;
                links = extractLinks(parserHtml, host);
            }
            std::map<std::string, int> word_freq;
            {
                std::lock_guard<std::mutex> lock(count_mutex);// Блокируем доступ к подсчету частоты слов
                std::cout << "Worker countWordFrequency. ID" << this_id << std::endl;
                word_freq = countWordFrequency(cleaned_text);
           
           db.addDataTable("Document", "title", urlDeep.url); // Добавляем документ
            for (const auto& [word, frequency] : word_freq) {
               db.addDataTable("Word", "name", word);
               
               //  Получаем ID документа и ID слова (это нужно реализовать)
                int documentId = db.select("Document", "title", urlDeep.url); // Выполняем выборку
                int wordId = db.select("Word", "name", word); // Выполняем выборку
                if (documentId == -1 || wordId ==-1) continue; 
                db.addWordDocuments("Document_Word", documentId, wordId, frequency);// Добавляем частоту слов
            }

      }

             for (const auto& link : links) {
                auto linkDeep = urlDeep.deep + 1;
                sq.push({ link, linkDeep }); // Увеличиваем глубину на 1
            }
            }
            catch (const std::exception& e) {
                std::cerr << "Exception in worker: " << e.what() << std::endl;
            }
    }
}



int main() {
    // Установка кодировки консоли на UTF-8
    //setlocale(LC_ALL, "Russian");
   system("chcp 65001");
   //SetConsoleCP(CP_UTF8);
   // SetConsoleOutputCP(CP_UTF8);

   try {

       //создаем базу данных
       clientdb r("dbwords");
       manage_db db("dbwords");
       //создаем таблицы клиентов и телефонов
       db.createTable("word", "document", "document_word");

       // db.addDataTable("Word", "ghbdtn багет");
        //db.addDataTable("Document", "слово");




       std::string url = "https://example.com";
       auto [host, target] = parseUrl(url);
       std::cout << "Host: " << host << std::endl;
       std::cout << "Target: " << target << std::endl;

       Safe_queue sq;
       int maxDeep = 3; // Задайте желаемую глубину рекурсии
       sq.push({ host + target, 1 }); // Начальная глубина 1

       int num_threads = std::thread::hardware_concurrency();
       std::cout << "Количество ядер: " << num_threads << std::endl;

       std::vector<std::thread> threads;
       for (int i = 0; i < num_threads-2; ++i) {
           threads.emplace_back(worker, std::ref(sq), maxDeep, std::ref(db));
       }
       for (auto& t : threads) {// Ждем завершения всех потоков
           if (t.joinable()) {
               t.join();
           }
       }
       std::cout << "All workers completed." << std::endl;

       //// Параметры сервера: адрес и порт
       //auto const address = net::ip::make_address("0.0.0.0"); // Принимаем на всех интерфейсах
       //unsigned short port = 8080; // Порт 80
       //net::io_context ioc{ 1 };

       //tcp::acceptor acceptor{ ioc, {address, port} };
       //tcp::socket socket{ ioc };

       //// Запуск HTTP сервера в отдельном потоке
       //std::thread server_thread([&]() {
       //    http_server(acceptor, socket, db);
       //    ioc.run();
       //    });

       //// Задержка перед открытием браузера
       //std::this_thread::sleep_for(std::chrono::seconds(1));

       //// Открываем браузер с нужной страницей
       //std::string urlserver = "http://localhost:8080/time";
       ////std::string command = "xdg-open " + url; // Для Linux
       //std::string command = "start " + urlserver; // Для Windows
       //// std::string command = "open " + url; // Для MacOS

       //system(command.c_str());

       //// Ожидаем завершения потока сервера

       //server_thread.join();



       //  // Выполняем GET запрос и получаем имя временного файла
       //  std::string parserHtml = http_get(host, port, target, version);
       //  TmpFile tempFile("./tmp");
       //  tempFile.writeToFile(parserHtml);
       //  std::cout << "Имя временного файла: " << tempFile.getUniqueName() << std::endl;
       // // tempFile.closeFile();
       //// tempFile.readFromFile();
       //     // Открытие HTML файла
       //  //std::ifstream file(tempFile.getUniqueName());
       //  //if (!file.is_open()) {
       //  //    throw HttpClientError("Ошибка при открытии файла!");
       //  //}

       //  // //Чтение содержимого файла
       //  //std::string html(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
       //  //file.close();

       //  // Очистка и обработка текста]

       //     std::string cleaned_text = clean_and_process_text(parserHtml);

       //  // Проверка на пустоту очищенного текста
       //  if (cleaned_text.empty()) {
       //      throw HttpClientError("Очищенный текст пуст!");
       //  }

       //  // Вывод результата
       //  std::cout << "Очищенный текст:" << std::endl;
       //  std::cout << cleaned_text << std::endl;

       //  std::map<std::string, int> word_freq = countWordFrequency(cleaned_text);

       //  // Выводим результаты
       //  std::cout << "Частота слов:" << std::endl;
       //  for (const auto& pair : word_freq) {
       //      std::cout << pair.first << ": " << pair.second << std::endl;
       //  }

       //  // Извлечение ссылок
       //  std::vector<std::string> links = extractLinks(parserHtml, host);

       //  // Вывод найденных ссылок
       //  std::cout << "Ссылки: " << std::endl;
       //  for (const auto& link : links) {
       //      std::cout << link << std::endl;
       //  }

       //     
   }
     catch (const std::exception& e) {
        std::cerr << "Ошибка:" << e.what() << std::endl;
        return EXIT_FAILURE;
    }

}