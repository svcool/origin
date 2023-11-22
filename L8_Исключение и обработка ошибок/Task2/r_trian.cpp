#include "r_trian.h"

right_triangle::right_triangle(double a, double b, double c, double A, double B, double C) : triangle(a, b, c, A, B, C) {
		name = "Прямоугольный треугольник";
		if (C != 90)
		{
			throw Except(name + " - угол С не равен 90 градусов");
		}

	}