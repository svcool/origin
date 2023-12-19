#include <iostream>

void swap(int& a, int& b) {
	int temp{};
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int a{5}, b{8};
	std::cout << "a = " << a << ", " << "b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", " << "b = " << b << std::endl;
	return 0;
}