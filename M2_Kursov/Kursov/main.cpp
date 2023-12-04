#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int type{}, S{}, a{};
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	std::cout << "1. Гонка для наземного транспорта" << std::endl;
	std::cout << "1. Гонка для воздушного транспорта" << std::endl;
	std::cout << "1. Гонка для наземного и воздушного транспорта" << std::endl;
	std::cout << "Выберите тип гонок: "; std::cin >> type;
	std::cout << "Укажите длину дистанции (должна быть положительной): "; std::cin >> S;
	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
	std::cout << "1. Зарегистрировать транспорт \n" << "Выберите действие: "; std::cin >> a;
	std::cout << ""
}