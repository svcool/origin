#include "greeter.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::string name;
	std::cout << "Введите имя: "; std::cin >> name;
	Greeter gr(name);
	
	gr.greet(name);
	system("pause");
}