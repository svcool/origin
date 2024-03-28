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
#include "exsept.h"

//void print(figure& triangle) {
//		triangle.get_name();
//		std::cout << "(стороны " << triangle. << ", " << b << ", " << c << "; углы" << A << ", " << B << ", " << C << ") " << "создан";
//
//	}
///////////////////////////////////////////
int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	try {
	triangle triangle(15, 20, 33, 60, 60, 60); //треугольник
	figure* f_triangle = &triangle;
	f_triangle->create_print_info();
	}
	catch (Except& ex) {
		std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
		std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	
	try {
	right_triangle right_triangle(15, 20, 33, 45, 45, 90); //прямоугольный треугольник (угол C всегда равен 90);
	figure* f_right_triangle = &right_triangle;
	f_right_triangle->create_print_info();
	}
	catch (Except& ex) {
	std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
	std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	
	try {
	isosceles_triangle isosceles_triangle(20, 33, 26, 60, 60, 60); //равнобедренный треугольник(стороны a и c равны, углы A и C равны);
	figure* f_isosceles_triangle = &isosceles_triangle;
	f_isosceles_triangle->create_print_info();
	}
	catch (Except& ex) {
		std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
		std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	
	try {
	estimated_triangle estimated_triangle(50, 50, 50, 60, 60 ,60);//равносторонний треугольник (все стороны равны, все углы равны 60);
	figure* f_estimated_triangle = &estimated_triangle;
	f_estimated_triangle->create_print_info();
	}
	catch (Except& ex) {
		std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
		std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	
	try {
	Quadrangle quandrangle(10, 20, 30, 40, 60, 90, 90, 90); //(стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
	figure* f_quandrangle = &quandrangle;
	f_quandrangle->create_print_info();
	}
	catch (Except& ex) {
		std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
		std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	
	try {
	rectangle rectangle(20, 50, 50, 45, 90, 90, 45, 90); //прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
	figure* f_rectangle = &rectangle;
	f_rectangle->create_print_info();
	}
	catch (Except& ex) {
		std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
		std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	
	try {
	square square(20, 50, 50, 45, 90, 90, 90, 90);//квадрат (все стороны равны, все углы равны 90);
	figure* f_square = &square;
	f_square->create_print_info();
	}
	catch (Except& ex) {
		std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
		std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	
	try {
	parallelogram parallelogram(20, 50, 50, 45, 90, 90, 45, 45);//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
	figure* f_parallelogram = &parallelogram;
	f_parallelogram->create_print_info();
	}
	catch (Except& ex) {
		std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
		std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	
	try {
	rhombus rhombus(20, 50, 50, 45, 90, 90, 45, 45);//ромб(все стороны равны, углы A, C и B, D попарно равны).
	figure* f_rhombus = &rhombus;
	f_rhombus->create_print_info();
	}
	catch (Except& ex) {
		std::cerr << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
		std::cerr << "Type: " << typeid(ex).name() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	/*figure* f_triangle = &triangle;
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
	f_rhombus->print_info();*/


	

}