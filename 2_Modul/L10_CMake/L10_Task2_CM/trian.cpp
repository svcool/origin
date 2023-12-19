#include "trian.h"
triangle::triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {
		name = "Треугольник";
	}

	void triangle::print_info() {
		std::cout << name << ":" << std::endl;
		std::cout << "Стороны: " << "a=" << a << ", b=" << b << ", c=" << c << std::endl;
		std::cout << "Углы: " << "A=" << A << ", B=" << B << ", C=" << C << std::endl;
		std::cout << std::endl;
	}