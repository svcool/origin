#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <atomic>
#include <stdexcept>

class Safe_queue {
    std::queue<std::string> task_queue;
    std::atomic<bool> stop = false;
    mutable std::mutex queue_mutex;
    std::condition_variable condit;

public:
    void push(std::string);
    std::string pop();
    std::string front();
    bool empty();
    size_t Size() const;
    void Stop();
};

#endif // SAFE_QUEUE_H
