#include "trian.h"
#include "exsept.h"
triangle::triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {
		name = "Треугольник";
		if ((A + B + C) != 180) { 
			throw Except(name + " - сумма углов не равна 180 градусов");

		}
	}
	void triangle::print_info() {
	std::cout << name << ":" << std::endl;
	std::cout << "Стороны: " << "a=" << a << ", b=" << b << ", c=" << c << std::endl;
	std::cout << "Углы: " << "A=" << A << ", B=" << B << ", C=" << C << std::endl;
	std::cout << std::endl;
	}
	void triangle::create_print_info() {
	std::cout << name << ":"
		<<"(стороны: " 
		<< a << ", " << b << ", " << c
		<< "; углы: " 
		<<  A << ", " << B << ", " << C 
		<< ") создан" << std::endl;
		}