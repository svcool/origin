#include "paral.h"
parallelogram::parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D) {
		name = "�������������";
		if ((a == c && b == d) && A == C && B == D) {
			throw Except(name + " - �� ������������ �������(������� a, c � b, d ������� �����, ���� A, C � B, D ������� �����)");
		}
	}
