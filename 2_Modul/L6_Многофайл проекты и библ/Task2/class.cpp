#include "class.h"
//����������� �� ���������
Counter::Counter(int number) {
	count = number;
}
//����������� �� ���������
Counter::Counter() {
	count = 1;
}
	void Counter::set_number(int number) {
		count = number;
	}
	void Counter::add() {
		count++;
	}
	void Counter::subtra��() {
		count--;
	}
	void Counter::print() {
		std::cout << count << "\n";
	}
