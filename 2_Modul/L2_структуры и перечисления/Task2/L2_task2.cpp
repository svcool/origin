#include <iostream>
struct person {
		std::string name;
		int count;
		double balance;
	};

void change_balance(person& p, double);

int main() {
	setlocale(LC_ALL, "Russin");
	system("chcp 1251");
	person p;
	double new_balance;
	std::cout << "Введите номер счета: ";
	std::cin >> p.count;
	std::cout << "Введите имя владельца: ";
	std::cin >> p.name;
	std::cout << "Введите баланс: ";
	std::cin >> p.balance;
	std::cout << "Введите новый баланс : ";
	std::cin >> new_balance;
	change_balance(p, new_balance);
	std::cout << "Ваш счет: " << p.name << ", " << p.count << ", " << p.balance;
	return 0;
}
void change_balance(person& p, double new_balance) {
	p.balance = new_balance;
}