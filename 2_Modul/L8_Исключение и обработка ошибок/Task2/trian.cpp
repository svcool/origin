#include "trian.h"
#include "exsept.h"
triangle::triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {
		name = "�����������";
		if ((A + B + C) != 180) { 
			throw Except(name + " - ����� ����� �� ����� 180 ��������");

		}
	}
	void triangle::print_info() {
	std::cout << name << ":" << std::endl;
	std::cout << "�������: " << "a=" << a << ", b=" << b << ", c=" << c << std::endl;
	std::cout << "����: " << "A=" << A << ", B=" << B << ", C=" << C << std::endl;
	std::cout << std::endl;
	}
	void triangle::create_print_info() {
	std::cout << name << ":"
		<<"(�������: " 
		<< a << ", " << b << ", " << c
		<< "; ����: " 
		<<  A << ", " << B << ", " << C 
		<< ") ������" << std::endl;
		}