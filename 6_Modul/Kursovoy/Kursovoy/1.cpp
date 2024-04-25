#include <iostream>
#include <queue>
#include <mutex>
#include <thread>

// Define a thread-safe task queue
template <typename T>
class ThreadSafeQueue {
private:
    std::queue<T> queue_;
    std::mutex mutex_;

public:
    // Add an item to the queue
    void push(const T& item) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(item);
    }

    // Remove and return an item from the queue
    T pop() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T item = queue_.front();
        queue_.pop();
        return item;
    }

    // Check if the queue is empty
    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

    // Get the size of the queue
    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }
};

// Example usage
int main() {
    ThreadSafeQueue<int> queue;

    // Producer thread
    std::thread producer([&]() {
        for (int i = 0; i < 10; ++i) {
            queue.push(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        });

    // Consumer thread
    std::thread consumer([&]() {
        while (true) {
            if (!queue.empty()) {
                int item = queue.pop();
                std::cout << "Consumed: " << item << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        });

    producer.join();
    consumer.join();

    return 0;
}

class ThreadPool {
private:
    std::vector<std::thread> threads_;
    ThreadSafeFunctionQueue queue_;
    size_t num_threads_;

public:
    ThreadPool(size_t num_threads) : num_threads_(num_threads) {
        for (size_t i = 0; i < num_threads_; ++i) {
            threads_.emplace_back([this]() {
                while (true) {
                    auto func = queue_.pop();
                    if (func == nullptr)
                        break;
                    func();
                }
                });
        }
    }

    ~ThreadPool() {
        queue_.stop();
        for (auto& thread : threads_) {
            thread.join();
        }
    }

    void submit(std::function<void()> func) {
        queue_.push(std::move(func));
    }
};