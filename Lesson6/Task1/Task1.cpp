#include <iostream>
#include "func.h"
#include "func.cpp"

int main() {
	int x, y, op;
		std::cout << "Введите первое число: ";
		std::cin >> x;
		std::cout << "Введите второе число: ";
		std::cin >> y;
		std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
		std::cin >> op;
		if (op == 1) std::cout << add(x, y);
		if (op == 2) subtraction(x, y);
		if (op == 3) multiplication(x, y);
		if (op == 4) division(x, y);
		if (op == 5) pow(x, y);
}