#pragma once
#include <iostream>
class Counter {
private:
	int count;
public:
	//конструктор со значениям
	Counter(int number);
	//конструктор по умолчанию
	Counter();
void set_number(int number);
void add();
void subtraсе();
void print();
};