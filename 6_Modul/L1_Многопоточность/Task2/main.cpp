#include<iostream>
#include<thread>
#include<chrono>
#include<vector>


void fillVector(std::vector<int>& v, unsigned n) {
	for (unsigned i = 1; i <= n; i++) {
		v.push_back(i);
	}
}

void print(const int* vector, const int size)
{
	for (int i = 0; i < size; ++i, std::cout << std::endl)
		std::cout << vector[i];
}

void sum(std::vector<int>& v_result, const std::vector<int>& v1, const std::vector<int>& v2, int count, int nt)
{
	//nt номер потока, count количество потоков
	size_t size = v1.size();

	//наибольший размер вектора иp v1,v2
	/*if (v1.size() > v2.size()) {
		size = v1.size();
	}
	else {
		size = v2.size();
	}*/
	//шаг для сложения векторов с округлением вверх
	int step = (static_cast<int>(size) + count - 1 )/ count;
	
		for (auto iter1 = v1.begin() + nt*step; iter1 != v1.begin() + (nt + 1)*step; iter1++){
			
			if (iter1 == v1.end()-1) break;
			int j = std::distance(v1.begin(), iter1);
			//std::cout << *iter1 << " " << std::distance(v1.begin(), iter1) << " " << v2[std::distance(v1.begin(), iter1)];
			v_result[std::distance(v1.begin(), iter1)] = *iter1 + v2[std::distance(v1.begin(), iter1)];
			//std::cout << v_result[std::distance(v1.begin(), iter1)] << " \n";
			
	}

}

int main() {
	std::vector<int> v1;
	std::vector<int> v2;
	unsigned n = 9; //размер вектора
	std::vector<int> result(n);
	fillVector(v1, n);
	fillVector(v2, n);
	size_t size = v1.size();
	for (auto& n  : v1) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	for (auto& n : v2) {
		std::cout << n << " ";
	}
	int count;
	unsigned int c = std::thread::hardware_concurrency();
	std::cout << c << " concurrent threads are supported.\n";
	std::cout << "Enter the number of flows: ";  std::cin >> count;

	std::vector<std::thread> threads;
	
	for (auto i = 0; i < count; ++i) {
		std::thread th(&sum, std::ref(result), std::ref(v1), std::ref(v2), count, i);
		threads.push_back(std::move(th));
	}
	
	/*for (int i=0;i<n;++i) {
		threads.push_back(std::thread(&foo, i));
		for (auto& th : ths) {
			th.join();
		}
	}*/

	for (std::thread& th : threads)
	{
		if (th.joinable())
			th.join();
	}

	for (auto& n : result) {
		std::cout << n << " ";
	}

	return 0;
}