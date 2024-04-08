#include<iostream>
#include<thread>
#include<chrono>
#include<vector>

void foo(std::size_t i) {}

void fillVector(std::vector<int>& v) {
	for (int i = 0; i < 100; i++) {
		v.push_back(i);
	}
}

void print(const int* vector, const size_t size)
{
	for (size_t i = 0; i < size; ++i, std::cout << std::endl)
		std::cout << vector[i];
}

int* sum(int* v_result, const int* v1, const int* v2, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
		v_result[i] = v1[i] + v2[i];
	return v_result;
}

int main() {
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> result;
	fillVector(v1);
	fillVector(v2);
	std::size_t count;
	std::cout << "Enter the number of flows: ";  std::cin >> count;

	int step = v1.size() / count;

	std::vector<std::thread> threads;
	for (auto i = 0; i < count; ++i) {
		std::thread th([=]()
			{
				threads_sum[i] = std::accumulate(v.begin() + i * step, v.begin() + (i + 1) * step, 0);
			});
		threds.push_back(std::move(th));
	}
	
	for (std::size_t i=0;i<n;++i) {
		threads.push_back(std::thread(&foo, i));
		for (auto& th : ths) {
			th.join();
		}
	}
	return 0;
}