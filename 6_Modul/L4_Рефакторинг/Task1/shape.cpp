#include"shape.h"
	void Shape::tranform_shift(int m, int n, int k) {
	switch (getType())
{
case 0:
	x1 += m; y1 += n;
	x2 += m; y2 += n;
	break;
case 1:
	x1 += m; y1 += n;
	x2 += m; y2 += n;
	x3 += m; y3 += n;
	x4 += m; y4 += n;
	break;
case 2:
	x1 += m; y1 += n; z1 += k;
	x2 += m; y2 += n; z2 += k;
	x3 += m; y3 += n; z3 += k;
	x4 += m; y4 += n; z4 += k;
	x5 += m; y5 += n; z5 += k;
	x6 += m; y6 += n; z6 += k;
	x7 += m; y7 += n; z7 += k;
	x8 += m; y8 += n; z8 += k;
	break;
}
};
	void Shape::tranform_scaleX(int a) {
		switch (getType())
		{
		case 0:
			x1 *= a;
			x2 *= a;
			break;
		case 1:
			x1 *= a;
			x2 *= a;
			x3 *= a;
			x4 *= a;
			break;
		case 2:
			x1 *= a;
			x2 *= a;
			x3 *= a;
			x4 *= a;
			x5 *= a;
			x6 *= a;
			x7 *= a;
			x8 *= a;
			break;
		}
	};
	void Shape::tranform_scaleY(int d) {
		switch (Shape::getType())
		{
		case 0:
			y1 *= d;
			y2 *= d;
			break;
		case 1:
			y1 *= d;
			y2 *= d;
			y3 *= d;
			y4 *= d;
			break;
		case 2:
			y1 *= d;
			y2 *= d;
			y3 *= d;
			y4 *= d;
			y5 *= d;
			y6 *= d;
			y7 *= d;
			y8 *= d;
			break;
		}
	};
	void Shape::tranform_scaleZ(int e) {
		switch (getType())
		{
		case 0:
			z1 *= e;
			z2 *= e;
			break;
		case 1:
			z1 *= e;
			z2 *= e;
			z3 *= e;
			z4 *= e;
			break;
		case 2:
			z1 *= e;
			y2 *= e;
			z3 *= e;
			z4 *= e;
			z5 *= e;
			z6 *= e;
			z7 *= e;
			z8 *= e;
			break;
		}
	};
	void Shape::tranform_scale(int s) {
		switch (getType())
		{
		case 0:
			x1 /= s; y1 /= s;
			x2 /= s; y2 /= s;
			break;
		case 1:
			x1 /= s; y1 /= s;
			x2 /= s; y2 /= s;
			x3 /= s; y3 /= s;
			x4 /= s; y4 /= s;
			break;
		case 2:
			x1 /= s; y1 /= s; z1 /= s;
			x2 /= s; y2 /= s; z2 /= s;
			x3 /= s; y3 /= s; z3 /= s;
			x4 /= s; y4 /= s; z4 /= s;
			x5 /= s; y5 /= s; z5 /= s;
			x6 /= s; y6 /= s; z6 /= s;
			x7 /= s; y7 /= s; z7 /= s;
			x8 /= s; y8 /= s; z8 /= s;
			break;
		}
	};

	int Shape::getType() const { return type; }

