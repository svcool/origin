#include "greeter.h"

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	std::string name;
	std::cout << "Введите имя: "; std::cin >> name;
	Greeter gr(name);
	
	gr.greet(name);
	system("pause");
}