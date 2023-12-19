#pragma once
#include "figure.h"
class triangle : public figure {
protected:
	double a{}, b{}, c{};
	double A{}, B{}, C{};
public:
	TRIAN_LIB_API triangle(double a, double b, double c, double A, double B, double C);

	void print_info() override;
};