#include<iostream>
#include<thread>
#include<chrono>

class Client {
	int count{};
	int max_client{};
	int nubmer_client{};
public:
	Client() = default;
	Client(int max_client) {
		this->max_client = max_client;
	};

	void add_count() {
		while(count < max_client) {
		count++;
		nubmer_client++;
		std::cout << "Client++:" << get_client();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout<< std::endl;
		}
	}
	
	void rm_count() {
		while(true) {
			nubmer_client--;
			std::cout << "  Operator: " << get_client();
			std::this_thread::sleep_for(std::chrono::seconds(2));
			if (count == max_client && nubmer_client == 0) break;
		}
	}

	int get_client() {
		return nubmer_client;
	}
};

class Operator {
	class Client c;

public:
		Operator(class Client &c) {
			this->c = c;
	};
	void rm_count() {
		c.rm_count();
	}
	
};


int main() {

	/*auto start = std::chrono::steady_clock::now();
	do_something();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";*/

	Client c(5);
	Operator op(c);

std::thread t1(&Client::add_count, &c);	
std::thread t2(&Operator::rm_count, &op);

	
	t1.join();
	t2.join();
}