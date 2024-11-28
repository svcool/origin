#include <safequeue.h>
#include <indexator.h>
#include <httpclient.h>
#include <tempfile.h>
#include <thread>
#include <future>
#include <mutex>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP

//void worker(Safe_queue& sq) {
//    while (true) {
//        std::string url;
//
//        {
//            if (sq.empty()) {
//                break; // Завершение работы, если очередь пуста
//            }
//            url = sq.front();
//            sq.pop();
//        }
//
//        download_page(url);
//    }
//}

int main() {
    // Установка кодировки консоли на UTF-8
    //setlocale(LC_ALL, "Russian");
   system("chcp 65001");
   SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try {
        // Параметры запроса
        std::string hos1t = "example.com";
        std::string port = "80";
        std::string target = "";
        int version = 11;


        std::string url = "https://netology.ru/profile/program/sqlcpp-14";

        
        size_t pos = url.find("/", 8); // 8 - длина "https://"

        if (pos == std::string::npos) {
            pos = url.length();
            std::string target = "";
        }
        else {
        std::string target = url.substr(pos); // Путь
        }
        std::string host = url.substr(0, pos); // Базовый URL
        
        std::cout << host <<"          " << target << std::endl;
//
//       std::string starthtml = host;
//        Safe_queue sq;
//        sq.push(starthtml);
//
//std::vector<std::future<void>> futures;
        // Запускаем пул потоков
     /*   for (int i = 0; i < num_workers; ++i) {

            futures.emplace_back(std::async(std::launch::async, worker));
        }*/

        // Ждем завершения всех потоков
      /*  for (auto& future : futures) {
            future.get();
        }*/


        // Выполняем GET запрос и получаем имя временного файла
        auto parserHtml = http_get(host, port, target, version);
        TmpFile tempFile("./tmp");
        tempFile.writeToFile(parserHtml);
        std::cout << "Имя временного файла: " << tempFile.getUniqueName() << std::endl;
       // tempFile.closeFile();
      // tempFile.readFromFile();

        // Получаем тело ответа в std::string
        //std::string response_body = boost::beast::buffers_to_string(parserHtml.body().data());

        // Открытие HTML файла
        //std::ifstream file(tempFile.getUniqueName());
        //if (!file.is_open()) {
        //    throw HttpClientError("Ошибка при открытии файла!");
        //}

        // //Чтение содержимого файла
        //std::string html(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
        //file.close();

        // Очистка и обработка текста]

       

        int num_workers = std::thread::hardware_concurrency();
        std::cout << "Количество ядер: " << num_workers << std::endl; //количество потоков


        std::string cleaned_text = clean_and_process_text(parserHtml);

        // Проверка на пустоту очищенного текста
        if (cleaned_text.empty()) {
            throw HttpClientError("Очищенный текст пуст!");
        }

        // Вывод результата
        std::cout << "Очищенный текст:" << std::endl;
        std::cout << cleaned_text << std::endl;

        std::map<std::string, int> word_freq = countWordFrequency(cleaned_text);

        // Выводим результаты
        std::cout << "Частота слов:" << std::endl;
        for (const auto& pair : word_freq) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }

        // Извлечение ссылок
        std::vector<std::string> links = extractLinks(parserHtml, host);

        // Вывод найденных ссылок
        std::cout << "Ссылки: " << std::endl;
        for (const auto& link : links) {
            std::cout << link << std::endl;
        }

        

        

        
    }
    catch (const HttpClientError& e) {
        std::cerr << "HTTP ошибка: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка:" << e.what() << std::endl;
        return EXIT_FAILURE;
    }

}