#include "SafeQueue.h"

void Safe_queue::push(std::string html) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        task_queue.push(html);
    }
    condit.notify_all();
}

std::string Safe_queue::pop() {
    std::unique_lock<std::mutex> lock(queue_mutex);
    {
        condit.wait(lock, [this] { return !task_queue.empty() || stop; });
    }
    if (stop && task_queue.empty()) {
        return nullptr;
    }

    if (task_queue.empty()) {
        throw std::runtime_error("Queue is empty");
    }
    auto item = std::move(task_queue.front());
    task_queue.pop();
    return item;
}

std::string Safe_queue::front() {
    std::lock_guard<std::mutex> lock(queue_mutex);
    if (task_queue.empty()) {
        return nullptr; // Или выбросьте исключение, если очередь пуста
    }
    return task_queue.front();
}

bool Safe_queue::empty() {
    std::lock_guard<std::mutex> lock(queue_mutex);
    return task_queue.empty();
}

size_t Safe_queue::Size() const {
    std::lock_guard<std::mutex> lock(queue_mutex);
    return task_queue.size();
}

void Safe_queue::Stop() {
    stop = true;
    condit.notify_all();
}
