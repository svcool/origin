#include "square.h"

square::square(double a, double b, double c, double d, double A, double B, double C, double D) : rhombus(a, b, c, d, A, B, C, D) {
		name = "Квадрат";
		if (A == 90 && B == 90 && C == 90 && D == 90) {
			throw Except(name + " - не соответствует условию (все стороны равны, все углы равны 90)");
		}
	}
