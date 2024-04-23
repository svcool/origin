#pragma once
#define _USE_MATH_DEFINES
#include<string>
class Shape
{
protected:
	int type;
	double volume;
	double square;
	double height;
	double radius;

	static const int line = 0;
	static const int sqr = 1;
	static const int cube = 2;
	static const int circle = 3;
	static const int cylinder = 4;

	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0,
		x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0,
		x5 = 0, y5 = 0, z5 = 0,
		x6 = 0, y6 = 0, z6 = 0,
		x7 = 0, y7 = 0, z7 = 0,
		x8 = 0, y8 = 0, z8 = 0;


	Shape() = default;

	void transform_shift(Shape& shape, int m, int n, int k);
	void transform_scaleX(Shape& shape, int a);
	void transform_scaleY(Shape& shape, int d);
	void transform_scaleZ(Shape& shape, int e);
	void transform_scale(Shape& shape, int s);
	
	int getType() const { return type; }


};

class Line : public Shape {
protected:

public:
	Line(int _x1, int _y1, int _x2, int _y2) {
	}
};

class Sqr :public Line {
protected:

public:
	Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) : Line(x1, y1, x2, y2) {
		type = 1;
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

};

class Cube : public Shape {
protected:

public:
	Cube(int _x1, int _y1, int _z1,
		int _x2, int _y2, int _z2,
		int _x3, int _y3, int _z3,
		int _x4, int _y4, int _z4,
		int _x5, int _y5, int _z5,
		int _x6, int _y6, int _z6,
		int _x7, int _y7, int _z7,
		int _x8, int _y8, int _z8) {
		type = 2;
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
};


class Circle : public Shape {
protected:

public:
	Circle(int _type, int _x1, int _y1, double R) {
		x1 = _x1; y1 = _y1;
		type = 3;
		// считаем площадь фигуры
		square = M_PI * R * R;
		// считаем объем фигуры
		volume = 0;
	}

};
class Cylinder : public Shape {
protected:

public:
	Cylinder(int _type, int _x1, int _y1, double R, double H) {
		x1 = _x1; y1 = _y1;
		radius = R;
		height = H;
		type = 4;
		// считаем площадь фигуры
		square = M_PI * R * R + 2 * R * height;
		// считаем объем фигуры
		volume = M_PI * R * R * height;
	}

};