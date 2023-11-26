#include "r_trian.h"

right_triangle::right_triangle(double a, double b, double c, double A, double B) : triangle(a, b, c, A, B, 90) {
		name = "Прямоугольный треугольник";
	}