#include<iostream>
#include<thread>
#include<chrono>
#include<vector>

void foo(std::size_t i) {}

void fillVector(std::vector<int>& v, unsigned n) {
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}
}

void print(const int* vector, const size_t size)
{
	for (size_t i = 0; i < size; ++i, std::cout << std::endl)
		std::cout << vector[i];
}

void sum(std::vector<int>& v_result, const std::vector<int>& v1, const std::vector<int>& v2, int count)
{
	size_t size{};
	std::vector <int>::iterator iter1, iter2;
	//iter1 = v1.begin();
	//iter2 = v1.begin();

	if (v1.size() > v2.size()) {
		size = v1.size();
	}
	else {
		size = v2.size();
	}

	int step =  size/count;
	for (auto iter1 = v1.begin(); iter1 != v1.end(); iter1++)
		cout << *iter1 << " ";
	cout << ")." << endl;
	//for (iter1 = v1.size(); i < (count + 1) * step; ++i)


	//for (size_t i = 0; i < size; ++i)
	//	//v_result[i] = v1[i] + v2[i];
	//return v_result;
}

int main() {
	std::vector<int> v1;
	std::vector<int> v2;
	unsigned n = 1000; //размер вектора
	std::vector<int> result;
	fillVector(v1, n);
	fillVector(v2, n);

	std::size_t count;

	std::cout << "Enter the number of flows: ";  std::cin >> count;

	int step = v1.size() / count;

	/*std::vector<std::thread> threads;
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
	}*/

	std::thread threads[10];
	for (auto& th : threads)
		th = std::thread([&]() {});

	return 0;
}