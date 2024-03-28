#include "quadr.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
		name = "Четырехугольник";
	}
	void Quadrangle::print_info() {
		std::cout << name << ":" << std::endl;
		std::cout << "Стороны: " << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
		std::cout << "Углы: " << "A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << std::endl;
		std::cout << std::endl;
	}