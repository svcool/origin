#include "SafeQueue.h"

void Safe_queue::push(UrlDeep html) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        task_queue.push(html);
    }
    condit.notify_one();
}
//�������� � ����������� 
UrlDeep Safe_queue::popFront() {
    UrlDeep item;
    std::unique_lock<std::mutex> lock(queue_mutex);
    condit.wait(lock, [this] { return !task_queue.empty() || stop; });

    if (stop && task_queue.empty()) {
        throw std::runtime_error("������� �����, �������� ���� ������������ �������");
    }

    if (!task_queue.empty()) {
        item = std::move(task_queue.front());
        task_queue.pop();
     }
    else {
        Stop();
        throw std::runtime_error("����������� ������");
    }
    return item;
}

UrlDeep Safe_queue::front() {
    std::lock_guard<std::mutex> lock(queue_mutex);
    if (task_queue.empty()) {
        throw std::runtime_error("������� �����"); 
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
//����������� ��� ������ �� �����
void Safe_queue::Stop() {
    stop = true;
    condit.notify_all();
}
