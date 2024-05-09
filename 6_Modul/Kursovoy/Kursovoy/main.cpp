#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional> 
#include <atomic>

class Safe_queue {
	//*метод push — записывает в начало очереди новую задачу.При этом захватывает мьютекс, а после окончания операции нотифицируется условная переменная;
	//*метод pop — находится в ожидании, пока не придёт уведомление на условную переменную.При нотификации условной переменной данные считываются из очереди;
	//*остальные методы на усмотрение разработчика.
	std::queue<std::function<void()>> task_queue;
	std::atomic<bool> stop = false;
	mutable std::mutex queue_mutex;
	std::condition_variable condit;
	
public:

	

	void push(std::function<void()> func) {
		{
			std::unique_lock<std::mutex> lock(queue_mutex);
			task_queue.push(func);
		}
		condit.notify_all();
	};

	std::function<void()> pop() {
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

	//
	bool empty() {
		std::lock_guard<std::mutex> lock(queue_mutex);
		return task_queue.empty();
	}
	//размер очереди
	size_t Size() const{
		std::lock_guard<std::mutex> lock(queue_mutex);
		return task_queue.size();
	}

	void Stop() {
		stop = true;
		condit.notify_all();
	}
};

class Thread_pool {
	std::vector<std::thread> threads;
	int count = std::thread::hardware_concurrency();
	Safe_queue& q;
	std::atomic<bool> stop;

public:
	Thread_pool(Safe_queue& sq, unsigned countThread = std::thread::hardware_concurrency()):q(sq),count(countThread), stop(false) {
		for (auto i = 0; i < count-2; i++) {
			threads.emplace_back([this] { this->work(); });
		}
	
	}

	//выбирает из очереди очередную задачу и исполняет её
	void work() {
		while (!stop) {
			auto func = q.pop();
			if (func == nullptr) {
				break;
			}
			func();
		}
	}
	//добавляем задачу в очередь
	void submit(std::function<void()> func) {
		q.push(std::move(func));
	}

	~Thread_pool() {
		stop = true; //остановка выборки очередной задачи
		q.Stop(); //разблокировка всех потоков в ожидании condit_v
		for (auto & th : threads)
		{
			stop = true;
			std::cout << threads.size();
			if (th.joinable()) {
		std::cout << "Stop thread (" << th.get_id() << ")" << std::endl;
				th.join();
			}
			
		}
	}
};
// Функция для ожидания нажатия клавиши и вызова деструктора пула потоков
void waitForKeypressAndDestroyPool(Thread_pool& pool) {
	std::cout << "Нажмите любую клавишу для выхода...\n";
	std::cin.get(); // Ожидаем ввод с клавиатуры
	std::cout << "Выход из программы...\n";
	// Вызываем деструктор пула потоков
	pool.~Thread_pool();
}


void task1() {
	std::cout << "The task1 is completed (" << std::this_thread::get_id() << ")" << std::endl;
}

void task2() {
	std::cout << "The task2 is completed (" << std::this_thread::get_id() << ")" << std::endl;
}

void task3() {
	std::cout << "The task2 is completed (" << std::this_thread::get_id() << ")" << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
		/*1. Объявить объект класса thread_pool.
		2. Описать несколько тестовых функций, выводящих в консоль своё имя.
		3. Раз в секунду класть в пул одновременно 2 функции и проверять их исполнение.*/
	std::function<void()> func1 = task1;
	std::function<void()> func2 = task3;
	std::function<void()> func3 = task3;

	unsigned countThread = std::thread::hardware_concurrency();
	std::cout << "Количество ядер: " << countThread << std::endl; //количество потоков

	//очередь
	Safe_queue sq;

	Thread_pool th(sq);
	//поток для завершения программы
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

