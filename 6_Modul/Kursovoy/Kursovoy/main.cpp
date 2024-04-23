#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>

class Safe_queue;

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
	std::queue<int> q;
	std::mutex mt;
	std::condition_variable x;

	void push() {};
	void pop() {};
};

void task1() {
	std::cout << "The task1 is completed" << std::endl;
}

void task2() {
	std::cout << "The task2 is completed" << std::endl;
}

void task3() {
	std::cout << "The task2 is completed" << std::endl;
}

int main() {
		/*1. Объявить объект класса thread_pool.
		2. Описать несколько тестовых функций, выводящих в консоль своё имя.
		3. Раз в секунду класть в пул одновременно 2 функции и проверять их исполнение.*/
}
