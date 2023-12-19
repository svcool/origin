#include <iostream>
long long fib(int x) {
	if (x == 0) {
		return 0;
	}
	else if (x == 1) {
		return 1;
	}
	else
		return fib(x - 1) + fib(x - 2);
}
int main(int argc, char** argv)
{
	int x{}, i{};
	std::cout << "Введите число: ";	
	std::cin >> x;
	std::cout << "Числа Фибоначчи: ";
	for (i = 0; i < x; i++){
	std::cout << fib(i);
	std::cout << " ";
	} 
	return 0;
}