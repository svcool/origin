#include <iostream>

enum class months {
	январь = 1,
	февраль,
	март,
	апрель,
	май,
	июнь,
	июль,
	август,
	сентябрь,
	октябрь,
	ноябрь,
	декабрь,
}; 

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); // настраиваем кодировку консоли 
	int number{};
	do {
		std::cout << "Введите номер месяца: ";
		std::cin >> number;
		months mon = static_cast<months>(number);
		if (number == 0) { std::cout << "До свидания" << std::endl; break; }
		switch (mon) {
		case months::январь: std::cout << "январь" << std::endl; break;
		case months::февраль: std::cout << "февраль" << std::endl; break;
		case months::март: std::cout << "март" << std::endl; break;
		case months::апрель: std::cout << "апрель" << std::endl; break;
		case months::май: std::cout << "май" << std::endl; break;
		case months::июнь: std::cout << "июнь" << std::endl; break;
		case months::июль: std::cout << "июль" << std::endl; break;
		case months::август: std::cout << "август" << std::endl; break;
		case months::сентябрь: std::cout << "сентябрь" << std::endl; break;
		case months::октябрь: std::cout << "октябрь" << std::endl; break;
		case months::ноябрь: std::cout << "ноябрь" << std::endl; break;
		case months::декабрь: std::cout << "декабрь" << std::endl; break;
		default: std::cout << "Неправильный номер!" << std::endl; break;
		}
	} while (number != 0);

	return 0;
}
