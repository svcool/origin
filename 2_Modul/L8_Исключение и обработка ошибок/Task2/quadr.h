#pragma once
#include "figure.h"
class Quadrangle : public figure {
protected:
	double a{}, b{}, c{}, d{}; //�������
	double A{}, B{}, C{}, D{}; //����
public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D);
	void print_info() override;
	void create_print_info() override;
};