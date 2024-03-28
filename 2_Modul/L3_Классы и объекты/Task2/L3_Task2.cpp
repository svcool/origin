#include <iostream>

class Counter {
private:
	int count;
public:
	//конструктор со значениям
	Counter(int number) {
		count = number;
	}
	//конструктор по умолчанию
	Counter() {
		count = 1;
	}

	void set_number(int number) {
		count = number;
	}
	void add() {
		count++;
	}
	void subtraсе() {
		count--;
	}
	void print() {
		std::cout << count << "\n";
	}
};

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

