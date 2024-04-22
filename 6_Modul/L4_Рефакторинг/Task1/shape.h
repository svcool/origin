#pragma once
#define _USE_MATH_DEFINES
#include<string>
#include<cmath>
class Shape
{
protected:
	int type;
	double volume;
	double square;
	double height;
	double radius;
	
public:
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
	

	void tranform_shift(int m, int n, int k);
	void tranform_scaleX(int a);
	void tranform_scaleY(int d);
	void tranform_scaleZ(int e);
	void tranform_scale(int s);

	int getType() const;
	
};


class Line : public Shape {
protected:

public:
	Line(int _x1, int _y1, int _x2, int _y2);
	
	void tranform_shift(int m, int n, int k);

	void tranform_scaleX(int a);

	void tranform_scaleY(int d);

	void tranform_scaleZ(int e);

	void tranform_scale(int s);
		
}; 


class Sqr : public Line {
protected:

public:
	Sqr(int _x1, int _y1,
		int _x2, int _y2,
		int _x3, int _y3,
		int _x4, int _y4);

	void tranform_shift(int m, int n, int k);

	void tranform_scaleX(int a);

	void tranform_scaleY(int d);

	void tranform_scaleZ(int e);

	void tranform_scale(int s);
};
		
class Cube:public Shape{
protected:
		
public:
	Cube(int _x1, int _y1, int _z1,
		int _x2, int _y2, int _z2,
		int _x3, int _y3, int _z3,
		int _x4, int _y4, int _z4,
		int _x5, int _y5, int _z5,
		int _x6, int _y6, int _z6,
		int _x7, int _y7, int _z7,
		int _x8, int _y8, int _z8);
	
	void tranform_shift(int m, int n, int k);

	void tranform_scaleX(int a);

	void tranform_scaleY(int d);

	void tranform_scaleZ(int e);

	void tranform_scale(int s);
};
		
class Circle : public Shape {
protected:

public:
	Circle(int _x1, int _y1, double R);
	void tranform_shift(int m, int n, int k);

	void tranform_scaleX(int a);

	void tranform_scaleY(int d);

	void tranform_scaleZ(int e);

	void tranform_scale(int s);
};

class Cylinder : public Shape {
protected:

public:
	Cylinder(int _x1, int _y1, double R, double H);
	
	void tranform_shift(int m, int n, int k);

	void tranform_scaleX(int a);

	void tranform_scaleY(int d);

	void tranform_scaleZ(int e);

	void tranform_scale(int s);
};
	
