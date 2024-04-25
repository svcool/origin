#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <queue>

class ThreadSafeFunctionQueue {
private:
    std::queue<std::function<void()>> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    void enqueue(std::function<void()> func) {
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_queue.push(func);
        }
        m_condition.notify_one();
    }

    std::function<void()> dequeue() {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condition.wait(lock, [this] { return !m_queue.empty(); });
        auto func = m_queue.front();
        m_queue.pop();
        return func;
    }
};

class ThreadPool {
private:
    std::vector<std::thread> m_threads;
    ThreadSafeFunctionQueue& m_functionQueue;
    bool m_stop;

public:
    ThreadPool(size_t numThreads, ThreadSafeFunctionQueue& functionQueue) : m_functionQueue(functionQueue), m_stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            m_threads.emplace_back([this]() {
                while (true) {
                    auto func = m_functionQueue.dequeue();
                    if (func == nullptr) break;
                    func();
                }
                });
        }
    }

    ~ThreadPool() {
        {
            std::lock_guard<std::mutex> lock(m_functionQueue.m_mutex);
            m_stop = true;
        }
        m_functionQueue.m_condition.notify_all();
        for (auto& thread : m_threads) {
            thread.join();
        }
    }

    template<class F, class... Args>
    void submit(F&& f, Args&&... args) {
        auto func = std::bind(std::forward<F>(f), std::forwardF > (args)...);
        m_functionQueue.enqueue(func);
    }
};

void testFunction1() {
    std::cout << "Test Function 1 executed by Thread ID: " << std::this_thread::get_id() << std::endl;
}

void testFunction2() {
    std::cout << "Test Function 2 executed by Thread ID: " << std::this_thread::get_id() << std::endl;
}

void testFunction3() {
    std::cout << "Test Function 3 executed by Thread ID: " << std::this_thread::get_id() << std::endl;
}

int main() {
    // Создаем потокобезопасную очередь для функций
    ThreadSafeFunctionQueue functionQueue;

    // Создаем пул из двух потоков
    ThreadPool threadPool(2, functionQueue);

    // Функции для добавления в пул
    std::function<void()> func1 = testFunction1;
    std::function<void()> func2 = testFunction2;
    std::function<void()> func3 = testFunction3;

    // Цикл для тестирования
    for (int i = 0; i < 5; ++i) {
        // Кладем две функции в потокобезопасную очередь
        functionQueue.enqueue(func1);
        functionQueue.enqueue(func2);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}