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
		switch (static_cast<int>(mon)) {
		case 0: std::cout << "До свидания" << std::endl; break;
		case 1: std::cout << "январь" << std::endl; break;
		case 2: std::cout << "февраль" << std::endl; break;
		case 3: std::cout << "март" << std::endl; break;
		case 4: std::cout << "апрель" << std::endl; break;
		case 5: std::cout << "май" << std::endl; break;
		case 6: std::cout << "июнь" << std::endl; break;
		case 7: std::cout << "июль" << std::endl; break;
		case 8: std::cout << "август" << std::endl; break;
		case 9: std::cout << "сентябрь" << std::endl; break;
		case 10: std::cout << "октябрь" << std::endl; break;
		case 11: std::cout << "ноябрь" << std::endl; break;
		case 12: std::cout << "декабрь" << std::endl; break;
		default: std::cout << "Неправильный номер!" << std::endl; break;
		}
	} while (number != 0);

	return 0;
}
