#include <iostream>

void swap(int* a, int* b) {
	int temp{};
	temp = *a;
	*a = *b;
	*b = temp;
	std::cout << "a = " << *a << ", b = " << *b << std::endl;

}

int main() {
	int a = 5, b = 10;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(&a, &b);
}