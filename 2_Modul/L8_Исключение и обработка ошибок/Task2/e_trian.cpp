#include "e_trian.h"
	estimated_triangle::estimated_triangle(double a, double b, double c, double A, double B, double C) : triangle(a, b, c, A, B, C) {
		name = "�������������� �����������";
		if (a == b && c == b && A == 60 && B == 60 && C == 60) {
			throw Except(name + " - ������� �� ����� ��� ���� �� ����� 60");
		
		}
	}
