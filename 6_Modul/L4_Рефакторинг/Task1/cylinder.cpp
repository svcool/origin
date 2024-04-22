#include"shape.h"

Cylinder::Cylinder(int _x1, int _y1, double R, double H) {
	// заполн¤ем координаты фигуры
	type = 4;
	x1 = _x1; y1 = _y1;
	radius = R;
	height = H;
	// считаем площадь фигуры
	square = M_PI * R * R + 2 * R * height;
	// считаем объем фигуры
	volume = M_PI * R * R * height;
}
void Cylinder::tranform_shift(int m, int n, int k) {
	Shape::tranform_shift(m, n, k);
}

void Cylinder::tranform_scaleX(int a) {
	Shape::tranform_scaleX(a);
}

void Cylinder::tranform_scaleY(int d) {
	Shape::tranform_scaleY(d);
}

void Cylinder::tranform_scaleZ(int e) {
	Shape::tranform_scaleZ(e);
}

void Cylinder::tranform_scale(int s) {
	Shape::tranform_scale;
}