#include"shape.h"

Line::Line(int _x1, int _y1, int _x2, int _y2) {
	type = 0;
	// считаем площадь фигуры
	square = 0;
	// считаем объем фигуры
	volume = 0;
}

void Line::tranform_shift(int m, int n, int k) {
	Shape::tranform_shift(m, n, k);
}

void Line::tranform_scaleX(int a) {
	Shape::tranform_scaleX(a);
}

void Line::tranform_scaleY(int d) {
	Shape::tranform_scaleY(d);
}

void Line::tranform_scaleZ(int e) {
	Shape::tranform_scaleZ(e);
}

void Line::tranform_scale(int s) {
	Shape::tranform_scale;
}