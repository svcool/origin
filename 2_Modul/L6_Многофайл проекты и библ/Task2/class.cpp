#include "class.h"
//конструктор со значениям
Counter::Counter(int number) {
	count = number;
}
//конструктор по умолчанию
Counter::Counter() {
	count = 1;
}
	void Counter::set_number(int number) {
		count = number;
	}
	void Counter::add() {
		count++;
	}
	void Counter::subtraсе() {
		count--;
	}
	void Counter::print() {
		std::cout << count << "\n";
	}
