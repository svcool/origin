#include <iostream>


class Calculator {
	Calculator (double num1, double num2) {
		num1;
		num2;
	}
private:
	double num1;
	double num2;
public:
	double add() {
		std::cout << "num1 + num2 = " << num1 + num2;
	}; //- метод должен возвращать результат сложения num1 и num2
	double multiply() {
		std::cout << "num1 * num2 = " << num1 * num2;
	}; //- метод должен возвращать результат перемножения num1 и num2
	double subtract_1_2() {
		std::cout << "num2 - num1 = " << num2 - num1;
	}; //- метод должен возвращать результат вычитания num2 из num1
	double subtract_2_1() {
		std::cout << "num1 + num2 = " << num1 + num2;
	};//- метод должен возвращать результат вычитания num1 из num2
	double divide_1_2() {
		std::cout << "num1/num2 = " << num1/num2;
	};//- метод должен возвращать результат деления num1 на num2
	double divide_2_1() {
		std::cout << "num2/num1 = " << num2/num1;
	};//- метод должен возвращать результат деления num2 на num1
	bool set_num1(double num1) {
	
	}; //- метод должен установить значение поля num1 равное значению аргумента num1 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
	bool set_num2(double num2) {
	
	};//- метод должен установить значение поля num2 равное значению аргумента num2 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
};

int main() {
	setlocale(LC_ALL, "Russin");
	system("chcp 1251");
	double num1{}, num2{};
	std::cout << "Введите num1: ";
	std::cin >> num1;
	std::cout << "Введите num1: ";
	std::cin >> num2;

}