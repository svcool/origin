#include "rhombus.h"
rhombus::rhombus(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D) {
		name = "����";
		if (a == b && b == c && c == d && A == C && B == D) {
			throw Except(name + " - �� ������������ ������� (��� ������� �����, ���� A, C � B, D ������� �����)");
		}
	}