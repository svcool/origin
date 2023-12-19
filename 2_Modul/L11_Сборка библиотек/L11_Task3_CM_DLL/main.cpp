#include "leaver.h"

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	std::string name;
	std::cout << "Введите имя: "; std::cin >> name;
	Leaver gr(name);
	
	gr.leave(name);
	system("pause");
}