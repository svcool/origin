#include <iostream>
#include <thread>
#include <functional>
#include <chrono>
#include <atomic>
#include <queue>
#include <vector>
#include <mutex>
#include <condition_variable>

class Safe_queue {
public:
    void push(std::function<void()> task) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(task);
        condition_.notify_one();
    }

    std::function<void()> pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return !queue_.empty(); });
        auto task = queue_.front();
        queue_.pop();
        return task;
    }

private:
    std::queue<std::function<void()>> queue_;
    std::mutex mutex_;
    std::condition_variable condition_;
};

class Thread_pool {
public:
    Thread_pool(Safe_queue& sq) : stop_(false) {
        for (unsigned i = 0; i < std::thread::hardware_concurrency(); ++i) {
            workers_.emplace_back([this, &sq] {
                while (true) {
                    auto task = sq.pop();
                    if (stop_ && !task) return;
                    task();
                }
                });
        }
    }

    ~Thread_pool() {
        stop_ = true;
        for (auto& worker : workers_) {
            worker.join();
        }
    }

    void submit(std::function<void()> task) {
        queue_.push(task);
    }

private:
    std::vector<std::thread> workers_;
    Safe_queue& queue_;
    std::atomic<bool> stop_;
};

void task1() {
    std::cout << "Выполнение задачи 1" << std::endl;
}

void task2() {
    std::cout << "Выполнение задачи 2" << std::endl;
}

void waitForKeypressAndDestroyPool(Thread_pool& pool) {
    std::cin.get(); // Ожидание нажатия клавиши
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    std::function<void()> func1 = task1;
    std::function<void()> func2 = task2;

    unsigned countThread = std::thread::hardware_concurrency();
    std::cout << "Количество ядер: " << countThread << std::endl; // количество потоков

    Safe_queue sq;
    Thread_pool th(sq);

    // поток для завершения программы
    std::thread keypressThread(waitForKeypressAndDestroyPool, std::ref(th));
    std::this_thread::sleep_for(std::chrono::seconds(1));

    for (int i = 0; i < 5; ++i) {
        // Кладем две функции в пул потоков
        th.submit(func1);
        th.submit(func2);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Присоединяем поток ожидания нажатия клавиши к основному потоку
    keypressThread.join();
}



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
            // Здесь можно добавить код для извлечения ссылок из read_buffer и добавления их в очередь
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
                break; // Завершение работы, если очередь пуста
            }
            url = url_queue.front();
            url_queue.pop();
        }

        download_page(url);
    }
}

int main() {
    // Добавляем начальные ссылки в очередь
    url_queue.push("http://example.com");
    url_queue.push("http://example.org");

    int num_workers = std::thread::hardware_concurrency();
    std::cout << "Количество ядер: " << countThread << std::endl; //количество потоков

    std::vector<std::future<void>> futures;

    // Запускаем пул потоков
    for (int i = 0; i < num_workers; ++i) {
        futures.emplace_back(std::async(std::launch::async, worker));
    }

    // Ждем завершения всех потоков
    for (auto& future : futures) {
        future.get();
    }

    return 0;
}
