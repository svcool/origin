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
		while(count != max_client) {
		count++;
		nubmer_client++;
		std::cout << get_client() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	
	virtual void rm_count() {
		while(nubmer_client >! 0) {
			nubmer_client--;
			std::cout << get_client() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	}

	int get_client() {
		return nubmer_client;
	}
};

int main() {

	/*auto start = std::chrono::steady_clock::now();
	do_something();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";*/

	Client c(10);
	
//std::thread t2(&Client::rm_count, &c);
std::thread t1(&Client::add_count, &c);
	
	t1.join();
	//t2.join();
}