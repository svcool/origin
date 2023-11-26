#include <iostream>

class Greeter {
sts:string name;
public:
 void greet(std::string name) {
	this->name = name;
	std::cout << "Здравствуйте, " << name << "!" << std::endl;

}

}

int main() {
	setlocale(LC_ALL, "Russian");
	Greater gr;
	std::cout << "Введите имя: "; std::cin >> name;
	gr.greet(name);
	system("pause");
}