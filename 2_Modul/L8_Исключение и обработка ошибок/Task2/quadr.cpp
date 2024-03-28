#include "quadr.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
		name = "���������������";
		if ((A + B + C + D) == 360) {
			throw Except(name + " - �� ������������ ������� (������� � ���� ������������, ���������� ������ ����� 4, ����� ����� ����� 360)");
		}
	}
	void Quadrangle::print_info() {
	std::cout << name << ":" << std::endl;
	std::cout << "�������: " << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
	std::cout << "����: " << "A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << std::endl;
	std::cout << std::endl;
	}

	void Quadrangle::create_print_info() {
		std::cout << name << ":"
			<< "(�������: "
			<< a << ", " << b << ", " << c << ", " << d
			<< "; ����: "
			<< A << ", " << B << ", " << C << ", " << D
			<< ") ������" << std::endl;
	}