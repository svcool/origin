#include"shape.h"

Circle::Circle(int _x1, int _y1, double R) {
	type = 3;
	// заполн¤ем координаты фигуры
	x1 = _x1; y1 = _y1;
	// считаем площадь фигуры
	square = M_PI * R * R;
	// считаем объем фигуры
	volume = 0;
}

void Circle::tranform_shift(int m, int n, int k) {
	Shape::tranform_shift(m, n, k);
}

void Circle::tranform_scaleX(int a) {
	Shape::tranform_scaleX(a);
}

void Circle::tranform_scaleY(int d) {
	Shape::tranform_scaleY(d);
}

void Circle::tranform_scaleZ(int e) {
	Shape::tranform_scaleZ(e);
}

void Circle::tranform_scale(int s) {
	Shape::tranform_scale;
}