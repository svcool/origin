#include "rect.h"

rectangle::rectangle(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D) {
		name = "�������������";
		if ((a == c && b == d) && A == 90 && B == 90 && C == 90 && D == 90) {
			throw Except(name + " - �� ������������ ������� (������� a, c � b, d ������� �����, ��� ���� ����� 90)");
		}

	}