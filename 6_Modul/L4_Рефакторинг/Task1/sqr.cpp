#include"shape.h"

Sqr::Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) : Line(x1, y1, x2, y2) {
	type = 1;
	// заполн¤ем координаты фигуры
	x3 = _x3; y3 = _y3;
	x4 = _x4; y4 = _y4;
	// стороны фигуры
	int a = abs(_x1 - _x2);
	int b = abs(_y1 - _y2);
	// считаем площадь фигуры
	square = a * b;
	// считаем объем фигуры
	volume = 0;
}
void Sqr::tranform_shift(int m, int n, int k) {
	Shape::tranform_shift(m, n, k);
}

void Sqr::tranform_scaleX(int a) {
	Shape::tranform_scaleX(a);
}

void Sqr::tranform_scaleY(int d) {
	Shape::tranform_scaleY(d);
}

void Sqr::tranform_scaleZ(int e) {
	Shape::tranform_scaleZ(e);
}

void Sqr::tranform_scale(int s) {
	Shape::tranform_scale;
}