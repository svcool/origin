#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	triangle triangle(5, 4, 5, 30, 50, 100); //треугольник
	right_triangle right_triangle(15, 50, 33, 45, 45, 90); //прямоугольный треугольник (угол C всегда равен 90);
	isosceles_triangle isosceles_triangle(15, 10, 15, 50, 60, 60); //равнобедренный треугольник(стороны a и c равны, углы A и C равны);
	estimated_triangle estimated_triangle(20, 20, 20, 60, 60, 60);//равносторонний треугольник (все стороны равны, все углы равны 60);
	Quadrangle quandrangle(10, 20, 44, 40, 90, 90, 90, 90); //прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
	rectangle rectangle(10, 20, 10, 20, 90, 90, 40, 90); //прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
	parallelogram parallelogram(10, 20, 30, 40, 90, 90, 90, 90);//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
	rhombus rhombus(20, 20, 20, 20, 135, 45, 135, 45);//ромб(все стороны равны, углы A, C и B, D попарно равны).
	square square(20, 20, 0, 20, 90, 90, 90, 90);//квадрат (все стороны равны, все углы равны 90);

	figure f;
	f.print_info();

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

	figure* f_parallelogram = &parallelogram;
	f_parallelogram->print_info();

	figure* f_rhombus = &rhombus;
	f_rhombus->print_info();

	figure* f_square = &square;
	f_square->print_info();

}