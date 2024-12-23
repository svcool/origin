﻿#include "SafeQueue.h"

void Safe_queue::push(UrlDeep html) {
	{
		std::unique_lock<std::mutex> lock(queue_mutex);
		task_queue.push(html);
	}
	condit.notify_one();
}
//удаление с извлечением 
UrlDeep Safe_queue::popFront() {
	UrlDeep item;
	std::unique_lock<std::mutex> lock(queue_mutex);
	condit.wait(lock, [this] { return !task_queue.empty() || stop; });

	if (stop && task_queue.empty()) {
		throw std::runtime_error("Очередь пуста");
	}

    // Извлечение элемента из очереди
    item = std::move(task_queue.front());
    task_queue.pop();
	
	return item;
}

UrlDeep Safe_queue::front() {
	std::lock_guard<std::mutex> lock(queue_mutex);
	if (task_queue.empty()) {
		throw std::runtime_error("Очередь пуста");
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
//освобождает все потоки по флагу
void Safe_queue::Stop() {
	std::lock_guard<std::mutex> lock(queue_mutex);
	stop = true;
	condit.notify_all();
}
