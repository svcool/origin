#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <mutex>
#include <curl/curl.h>

std::mutex queue_mutex;
std::queue<std::string> url_queue;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void download_page(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string read_buffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Failed to download " << url << ": " << curl_easy_strerror(res) << std::endl;
        }
        else {
            std::cout << "Downloaded " << url << " successfully." << std::endl;
            // «десь можно добавить код дл€ извлечени€ ссылок из read_buffer и добавлени€ их в очередь
        }

        curl_easy_cleanup(curl);
    }
}

void worker() {
    while (true) {
        std::string url;

        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            if (url_queue.empty()) {
                break; // «авершение работы, если очередь пуста
            }
            url = url_queue.front();
            url_queue.pop();
        }

        download_page(url);
    }
}

int main31232() {
    // ƒобавл€ем начальные ссылки в очередь
    url_queue.push("http://example.com");
    url_queue.push("http://example.org");

    int num_workers = std::thread::hardware_concurrency();
    std::cout << " оличество €дер: " << countThread << std::endl; //количество потоков

    std::vector<std::future<void>> futures;

    // «апускаем пул потоков
    for (int i = 0; i < num_workers; ++i) {
        futures.emplace_back(std::async(std::launch::async, worker));
    }

    // ∆дем завершени€ всех потоков
    for (auto& future : futures) {
        future.get();
    }

    return 0;
}
