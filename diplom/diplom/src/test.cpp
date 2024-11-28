#include <safequeue.h>
#include <indexator.h>
#include <httpclient.h>
#include <tempfile.h>
#include <thread>
#include <future>
#include <mutex>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP


// Глобальные мьютексы для защиты функций
std::mutex http_mutex;
std::mutex clean_mutex;
std::mutex extract_mutex;
std::mutex count_mutex;

std::pair<std::string, std::string> parseUrl(const std::string& url) {

    std::string host;
    std::string target;
    // Удаляем протокол (http:// или https://)
    std::string cleanUrl = std::regex_replace(url, std::regex(R"(^https?://)"), "");

    // Находим позицию первого символа '/' после базового URL
    size_t pos = cleanUrl.find("/");

    // Переменные для базового URL и пути
    

    if (pos == std::string::npos) {
        // Если '/' не найден, значит, весь URL - это хост
        host = cleanUrl;
        target = "/"; // Путь пустой
    }
    else {
        // Извлекаем базовый URL и путь
        host = cleanUrl.substr(0, pos); // Базовый URL
        target = cleanUrl.substr(pos);   // Путь
    }

    return std::make_pair(host, target); // Возвращаем пару (базовый URL, путь)
}
void worker(Safe_queue& sq) {
    std::cout << "Worker started." << std::endl; // Отладочный вывод
    while (true) {
        std::string url;
            url = sq.pop();
            // Вызов функции для парсинга URL
            auto [host, target] = parseUrl(url);

            // Если URL пустой, это означает, что таймаут истек
            if (url.empty()) {
                std::cout << "Worker exiting due to empty URL." << std::endl; // Отладочный вывод
                break; // Завершение работы, если очередь пуста в течение 10 секунд
            }
            try {
            // Блокируем доступ к http_get
            std::string parserHtml;
            {
                std::lock_guard<std::mutex> lock(http_mutex);
                // Добавляем задержку в 2 секунды перед выполнением запроса
                std::this_thread::sleep_for(std::chrono::seconds(2));
                parserHtml = http_get(host, "80", target, 11);
            }

            // Блокируем доступ к очистке и обработке текста
            std::string cleaned_text;
            {
                std::lock_guard<std::mutex> lock(clean_mutex);
                cleaned_text = clean_and_process_text(parserHtml);
            }

            // Блокируем доступ к извлечению ссылок
            std::vector<std::string> links;
            {
                std::lock_guard<std::mutex> lock(extract_mutex);
                links = extractLinks(parserHtml, host);
            }

            // Блокируем доступ к подсчету частоты слов
            std::map<std::string, int> word_freq;
            {
                std::lock_guard<std::mutex> lock(count_mutex);
                word_freq = countWordFrequency(cleaned_text);
            }

            // Обработка извлеченных ссылок
            for (const auto& link : links) {
                sq.push(link); // добавление в очередь
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
   SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try {
        // Параметры запроса
        /*std::string host = "https://ya.ru";
        
        std::string target = "/";
        */
int version = 11;
std::string port = "80";
        std::string url = "https://otzovik.com/";

        // Вызов функции для парсинга URL
        auto [host, target] = parseUrl(url);

        // Вывод результатов
        std::cout << "Host: " << host << std::endl;   // Вывод базового URL
        std::cout << "Target: " << target << std::endl; // Вывод пути
//
       std::string starthtml = host;
       Safe_queue sq;
       sq.push(starthtml+target);
// Количество потоков
       int num_threads = std::thread::hardware_concurrency();
       std::cout << "Количество ядер: " << num_threads << std::endl; //количество потоков
       std::vector<std::thread> threads;

       // Запуск потоков
       for (int i = 0; i < 2; ++i) {
           threads.emplace_back(worker, std::ref(sq));
       }

       // Ждем завершения всех потоков
       for (auto& t : threads) {
           if (t.joinable()) {
               t.join();
           }
       }

       std::cout << "All workers completed." << std::endl;

        
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
    catch (const HttpClientError& e) {
        std::cerr << "HTTP ошибка: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка:" << e.what() << std::endl;
        return EXIT_FAILURE;
    }

}