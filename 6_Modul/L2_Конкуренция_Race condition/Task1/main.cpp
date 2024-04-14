#include<iostream>
#include<thread>
#include<chrono>
#include<atomic>

class Queue {
	int count{};
	int max_client{};
	std::atomic<int> nubmer_client{};
public:
	Queue() = default;
	Queue(int max_client) {
		std::cout << "atomic.is_lock_free: " << nubmer_client.is_lock_free() <<"\n";
		this->max_client = max_client;
	};

	void add_count() {
		while (count < max_client) {
			count++;
			nubmer_client++;
			std::cout << "Client++:" << get_client() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}

	void rm_count() {
		while (true) {
			nubmer_client--;
			std::cout << "  Operator: " << get_client() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			if (count == max_client && nubmer_client == 0) break;
		}
	}

	int get_client() {
		return nubmer_client.load();
	}
};



int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int n = 10; //максимальное количество клиентов
	Queue q(10);

	std::thread t1(&Queue::add_count, &q);
	std::thread t2(&Queue::rm_count, &q);

	t1.join();
	t2.join();

	std::cout << "Клиенты закончились" << std::endl;
}