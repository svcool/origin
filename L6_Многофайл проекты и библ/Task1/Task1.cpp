#include <iostream>
#include "func.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int x, y, op;
		std::cout << "Введите первое число: ";
		std::cin >> x;
		std::cout << "Введите второе число: ";
		std::cin >> y;
		std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
		std::cin >> op;
		if (op == 1) std::cout << "Сумма " << x << " и " << y << " = " << add(x,y) << std::endl;
		if (op == 2) std::cout << "Разность " << x << " и " << y << " = " << subtraction(x, y) << std::endl; ;
		if (op == 3) std::cout << "Произведение " << x << " и " << y << " = " << multiplication(x, y) << std::endl;
		if (op == 4) std::cout << "Деление " << x << " и " << y << " = " << division(x, y);
		if (op == 5) std::cout << x << " в степени " << y << " = " << pow(x, y) << std::endl;;
}
