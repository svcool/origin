#include <iostream>
#include "2_race.h"
#include "1_transport.h"



int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	Transport tr("");
	Race rc(0);
	int type{}, S{}, a{};
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	std::cout << "1. Гонка для наземного транспорта" << std::endl;
	std::cout << "2. Гонка для воздушного транспорта" << std::endl;
	std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
	std::cout << "Выберите тип гонок: "; std::cin >> type;
	std::cout << "Укажите длину дистанции (должна быть положительной): "; std::cin >> S;
	
	do {
	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
	std::cout << "1. Зарегистрировать транспорт \n" << "Выберите действие: "; std::cin >> a;


	} while (a == 0);
	
	std::cout << ""
}