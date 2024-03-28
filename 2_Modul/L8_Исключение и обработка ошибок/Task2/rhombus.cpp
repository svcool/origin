#include "rhombus.h"
rhombus::rhombus(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D) {
		name = "Ромб";
		if (a == b && b == c && c == d && A == C && B == D) {
			throw Except(name + " - не соответсвует условию (все стороны равны, углы A, C и B, D попарно равны)");
		}
	}