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

	//шаг для сложения векторов с округлением вверх
	int step = (static_cast<int>(size) + count - 1 )/ count;
	
		if (nt == count - 1) {
			auto end_vector = v1.end();
			for (auto iter1 = v1.begin() + nt * step; iter1 != v1.end(); iter1++) {
			v_result[std::distance(v1.begin(), iter1)] = *iter1 + v2[std::distance(v1.begin(), iter1)];
			std::cout << v_result[std::distance(v1.begin(), iter1)] << " \n";
			
	}

			}
		}
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	std::vector<int> v1;
	std::vector<int> v2;
	unsigned n = 1000; //размер вектора
	std::vector<int> result(n);
	fillVector(v1, n);
	fillVector(v2, n);

//	size_t size = v1.size();

	int count;
	unsigned int c = std::thread::hardware_concurrency();
	std::cout << "Количество аппаратных ядер - " << c << "\n";
	std::cout << "Выберите количество ядер: ";  std::cin >> count;

	std::vector<std::thread> threads;
	std::vector<std::chrono::duration<double>> time_thr;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
	
	try
	{
		for (auto i = 0; i < count; ++i) {
			start = std::chrono::steady_clock::now();
			
			std::thread th(&sum, std::ref(result), std::ref(v1), std::ref(v2), count, i);
			
			end = std::chrono::steady_clock::now();

			std::chrono::duration<double> el = end - start;

			time_thr.push_back(std::move(el));
		
			threads.push_back(std::move(th));
		}

		for (std::thread& th : threads)
		{
			if (th.joinable())
					th.join();
		}
	}
	catch (const std::exception& err)
	{
	std::cout << "\n" << err.what()<<"\n";
	}

	for (int i = 1; i < count + 1; ++i) {
		std::cout << i + 1 << " потоков";

	}
	
	
	for (auto& n : time_thr) {
		std::cout << n.count() << " ";
	}

	//for (auto& n : result) {
	//	std::cout << n << " ";
	//}

	return 0;
}