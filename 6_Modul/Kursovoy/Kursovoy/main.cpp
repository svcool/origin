#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional> 

class Safe_queue;
std::mutex mt;

class Thread_pool {
	std::vector<std::thread> threads;
	int count = std::thread::hardware_concurrency();
	Safe_queue sq;
	/**вектор потоков, которые инициализируют в конструкторе класса и уничтожают в деструкторе;
	*потокобезопасная очередь задач для хранения очереди работ;
	*остальные поля на усмотрение разработчика.*/
	Thread_pool() {

	}

	void thread() {
		for (int i = 1; i < count + 1; ++i) {
			std::thread th(1,1);
			threads.push_back(std::move(th));

			for (std::thread& th : threads)
			{
				if (th.joinable())
					th.join();
			}

		}
	}

	void work() {}
	void submit() {}


	~Thread_pool(){

	}

};

class Safe_queue {
	//*метод push — записывает в начало очереди новую задачу.При этом захватывает мьютекс, а после окончания операции нотифицируется условная переменная;
	//*метод pop — находится в ожидании, пока не придёт уведомление на условную переменную.При нотификации условной переменной данные считываются из очереди;
	//*остальные методы на усмотрение разработчика.
	std::queue<std::function<void()>> q;
	std::mutex mt;
	std::condition_variable condit;

	void push(std::function<void()> func) {
		std::unique_lock<std::mutex> lock(mt);
		q.push(func);
		condit.notify_one();
		
	};
	std::function<void()> pop() {
		std::unique_lock<std::mutex> lock(mt);
		condit.wait(lock, [this] { return !q.empty(); });
		auto task = std::move(q.front());
		q.pop();
		return task;
	}

	void execute() {
		while (true) {
			std::unique_lock<std::mutex> lock(mutex);
			condition.wait(lock, [this] { return !queue.empty(); });
			auto func = queue.front();
			queue.pop();
			lock.unlock();
			func();
		}
};

void task1() {
	std::cout << "The task1 is completed ("<< std::this_thread::get_id() << ")" << std::endl;
}

void task2() {
	std::cout << "The task1 is completed (" << std::this_thread::get_id() << ")" << std::endl;
}

void task3() {
	std::cout << "The task1 is completed (" << std::this_thread::get_id() << ")" << std::endl;
}

int main() {
		/*1. Объявить объект класса thread_pool.
		2. Описать несколько тестовых функций, выводящих в консоль своё имя.
		3. Раз в секунду класть в пул одновременно 2 функции и проверять их исполнение.*/
	std::function<void()> func;
	func = task1;

}


