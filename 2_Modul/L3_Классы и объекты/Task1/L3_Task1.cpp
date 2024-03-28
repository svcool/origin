#include <iostream>


class Calculator {
private:
	double num1;
	double num2;

public:
	double add(double num1, double num2) {
		return num1 + num2;
	}; //- метод должен возвращать результат сложения num1 и num2
	double multiply(double num1, double num2) {
		return num1 * num2;
	}; //- метод должен возвращать результат перемножения num1 и num2
	double subtract_1_2(double num1, double num2) {
		return num1 - num2;
	}; //- метод должен возвращать результат вычитания num2 из num1
	double subtract_2_1(double num1, double num2) {
		return num2 - num1;
	};//- метод должен возвращать результат вычитания num1 из num2
	double divide_1_2(double num1, double num2) {
		return num1/num2;
	};//- метод должен возвращать результат деления num1 на num2
	double divide_2_1(double num1, double num2) {
		return num2/num1;
	};//- метод должен возвращать результат деления num2 на num1
	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		else
			return false;
	}; //- метод должен установить значение поля num1 равное значению аргумента num1 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		else 
			return false;
	
	};//- метод должен установить значение поля num2 равное значению аргумента num2 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
	void error() {
		std::cout << "Неверный ввод!" << std::endl;
	}

	void out() {
		std::cout << "num1 + num2 = " << add(num1, num2) << std::endl;
		std::cout << "num2 * num1 = " << multiply(num1, num2) << std::endl;
		std::cout << "num1 - num2 = " << subtract_1_2(num1, num2) << std::endl;
		std::cout << "num2 - num1 = " << subtract_2_1(num1, num2) << std::endl;
		std::cout << "num1 / num2 = " << divide_1_2(num1, num2) << std::endl;
		std::cout << "num2 / num1 = " << divide_2_1(num1, num2) << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russin");
	system("chcp 1251");
	double num1{}, num2{};
	bool n1 = false, n2 = false;
	Calculator objCalculator;
	while (true) {
		// проверка первого значения
		while (n1 == false) {
			std::cout << "Введите num1: "; 	std::cin >> num1;
			n1 = objCalculator.set_num1(num1);
			if (n1 == false) {
				objCalculator.error();
				n1 = false;
			}
		}
		// проверка второго значения
		while (n2 == false) {
			std::cout << "Введите num2: "; 	std::cin >> num2;
			n2 = objCalculator.set_num1(num1);
			if (objCalculator.set_num2(num2) == false) {
				objCalculator.error();
				n2 = objCalculator.set_num2(num2);
			}
		}
		objCalculator.out();
					n1 = false; n2 = false;
	}
}