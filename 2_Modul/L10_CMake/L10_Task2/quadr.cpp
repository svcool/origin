#include "quadr.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
		name = "���������������";
	}
	void Quadrangle::print_info() {
		std::cout << name << ":" << std::endl;
		std::cout << "�������: " << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
		std::cout << "����: " << "A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << std::endl;
		std::cout << std::endl;
	}