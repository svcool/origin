#include "trian.h"
triangle::triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {
		name = "�����������";
	}

	void triangle::print_info() {
		std::cout << name << ":" << std::endl;
		std::cout << "�������: " << "a=" << a << ", b=" << b << ", c=" << c << std::endl;
		std::cout << "����: " << "A=" << A << ", B=" << B << ", C=" << C << std::endl;
		std::cout << std::endl;
	}