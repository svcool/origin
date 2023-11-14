#include "figure.h"
#include "trian.h"
#include "quadr.h"
#include "e_trian.h"
#include "is_trian.h"
#include "paral.h"
#include "r_trian.h"
#include "rect.h"
#include "rhombus.h"
#include "square.h"


///////////////////////////////////////////
int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	triangle triangle(15, 20, 33, 55, 64, 44); //треугольник
	right_triangle right_triangle(15, 20, 33, 55, 44); //прямоугольный треугольник (угол C всегда равен 90);
	isosceles_triangle isosceles_triangle(15, 20, 33, 26); //равнобедренный треугольник(стороны a и c равны, углы A и C равны);
	estimated_triangle estimated_triangle(50);//равносторонний треугольник (все стороны равны, все углы равны 60);
	Quadrangle quandrangle(10, 20, 30, 40, 60, 90, 90, 90); //прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
	rectangle rectangle(20, 50); //прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
	square square(50);//квадрат (все стороны равны, все углы равны 90);
	parallelogram parallelogram(23, 33, 40, 40);//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
	rhombus rhombus(22, 77, 60);//ромб(все стороны равны, углы A, C и B, D попарно равны).


	figure* f_triangle = &triangle;
	f_triangle->print_info();


	figure* f_right_triangle = &right_triangle;
	f_right_triangle->print_info();

	figure* f_isosceles_triangle = &isosceles_triangle;
	f_isosceles_triangle->print_info();

	figure* f_estimated_triangle = &estimated_triangle;
	f_estimated_triangle->print_info();

	figure* f_quandrangle = &quandrangle;
	f_quandrangle->print_info();

	figure* f_rectangle = &rectangle;
	f_rectangle->print_info();

	figure* f_square = &square;
	f_square->print_info();

	figure* f_parallelogram = &parallelogram;
	f_parallelogram->print_info();

	figure* f_rhombus = &rhombus;
	f_rhombus->print_info();

}