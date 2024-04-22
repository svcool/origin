#include"shape.h"

Cube::Cube(
	int _x1, int _y1, int _z1,
	int _x2, int _y2, int _z2,
	int _x3, int _y3, int _z3,
	int _x4, int _y4, int _z4,
	int _x5, int _y5, int _z5,
	int _x6, int _y6, int _z6,
	int _x7, int _y7, int _z7,
	int _x8, int _y8, int _z8) {
	type = 2;
	// заполн¤ем координаты фигуры
	x1 = _x1; y1 = _y1; z1 = _z1;
	x2 = _x2; y2 = _y2; z2 = _z2;
	x3 = _x3; y3 = _y3; z3 = _z3;
	x4 = _x4; y4 = _y4; z4 = _z4;
	x5 = _x5; y5 = _y5; z5 = _z5;
	x6 = _x6; y6 = _y6; z6 = _z6;
	x7 = _x7; y7 = _y7; z7 = _z7;
	x8 = _x8; y8 = _y8; z8 = _z8;
	// стороны фигуры
	int a = abs(_x1 - _x2);
	int b = abs(_y1 - _y2);
	int c = abs(_z1 - _z2);
	// считаем площадь фигуры
	square = 2 * a * b + 2 * a * c + 2 * b * c;
	// считаем объем фигуры
	volume = a * b * c;
}
void Cube::tranform_shift(int m, int n, int k) {
	Shape::tranform_shift(m, n, k);
}

void Cube::tranform_scaleX(int a) {
	Shape::tranform_scaleX(a);
}

void Cube::tranform_scaleY(int d) {
	Shape::tranform_scaleY(d);
}

void Cube::tranform_scaleZ(int e) {
	Shape::tranform_scaleZ(e);
}

void Cube::tranform_scale(int s) {
	Shape::tranform_scale;
}