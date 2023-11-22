#include "paral.h"
parallelogram::parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D) {
		name = "Параллелограм";
		if ((a == c && b == d) && A == C && B == D) {
			throw Except(name + " - не соответсвует условию(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны)");
		}
	}
