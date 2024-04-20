#pragma once
#include"shape.h"
class Transform
{
public:

	Shape shift(int m, int n, int k);
	Shape scaleX(int a);
	Shape scaleY(int d);
	Shape scaleZ(int e);
	Shape scale(int s);

private:
	Shape shape;
};

