#include "is_trian.h"

isosceles_triangle::isosceles_triangle(double a, double b, double c, double A, double B, double C) : triangle(a, b, c, A, B, C) {
		name = "Равнобедренный треугольник";
		if (a == c && A == C) {
			throw Except(name + " - сторона a не равна с или угол А не равен С");
		}
	}
