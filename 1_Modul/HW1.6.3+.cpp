#include <iostream>
int main(int argc, char** argv)
{
	int x{};
	std::cout << "Введите число: ";
	std::cin >> x;
	std::cout << "Числа Фибоначчи: ";
	long long temp1{ 0 }, temp2{ 1 }, res{ 0 };
	if (x == 0 || x == 1) std::cout << 0;
	if (x >= 2) std::cout << "0 1 ";
	for (int i = 2; i < x; i++) { 
			res = temp2 + temp1;
			temp1 = temp2;
			temp2 = res;
			std::cout << res;
			std::cout << " ";
		}

	int arr[x]{};





	return 0;
}