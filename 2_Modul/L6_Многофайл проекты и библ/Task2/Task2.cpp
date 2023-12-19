#include "class.h"
int main() {
	setlocale(LC_ALL, "Russin");
	system("chcp 1251");
	Counter c;
	std::string yes_no{};
	int number{};
	std::string cnd{};
	//>>>>>	//Counter* ptr = &c; //работа через указатель
	while (yes_no != "нет") {
		std::cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет :"; std::cin >> yes_no;
		if (yes_no == "да") {
			std::cout << "Введите начальное значение счётчика :";
			std::cin >> number;
			c.set_number(number);
			//>>>>>>>		//*ptr = number; // работа через указатель
			break;
		}
	}
	while (cnd != "x") {
		std::cout << "Введите команду ('+', '-', '=' или 'x'):";
		std::cin >> cnd;
		if (cnd == "+") c.add();
		if (cnd == "-") c.subtraсе();
		if (cnd == "=") c.print();
		if (cnd == "x") {
			std::cout << "До свидания!";
			return 0;
		}
	}
	return 0;
}

