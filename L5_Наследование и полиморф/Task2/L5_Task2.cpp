#include <iostream>

class figure {
protected:
	std::string name;
public:
	virtual void print_info() { std::cout << name; }
};
//////////////////////////////////////////////
class triangle : public figure {
protected:
	double a{}, b{}, c{};
	double A{}, B{}, C{};
public:
	triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C){
		name = "Треугольник";
	}

	void print_info() override {
		std::cout << name << ":" << std::endl;
		std::cout << "Стороны: " << "a=" << a << ", b=" << b << ", c=" << c << std::endl;
		std::cout << "Углы: " << "A=" << A << ", B=" << B << ", C=" << C << std::endl;
		std::cout << std::endl;
	}

};
///////////////////////////////////////
class Quadrangle : public figure {
protected:
    double a{}, b{}, c{}, d{}; //стороны
    double A{}, B{}, C{}, D{}; //углы
public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        name = "Четырехугольник";
    }
    void print_info() override {
        std::cout << name << ":" << std::endl;
        std::cout << "Стороны: " << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
        std::cout << "Углы: " << "A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << std::endl;
        std::cout << std::endl;
    }
};

//прямоугольный треугольник (угол C всегда равен 90);
class right_triangle : public triangle {
public:
	right_triangle(double a, double b, double c, double A, double B) : triangle(a, b, c, A, B, 90) {
	name = "Прямоугольный треугольник";
	}
};
//равнобедренный треугольник(стороны a и c равны, углы A и C равны);
class isosceles_triangle : public triangle {
public:
	isosceles_triangle(double a, double b, double A, double B) : triangle(a, b, a, A, B, A) {
		name = "Равнобедренный треугольник";
	}
};
//равносторонний треугольник (все стороны равны, все углы равны 60);
class estimated_triangle : public triangle{
public:
	estimated_triangle(double a) : triangle(a, a, a, 60, 60, 60) {
		name = "Равносторониий треугольник";
	}
};
//прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
class rectangle : public Quadrangle
{
public:
	rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
		name = "Прямоугольник";
	}
};

//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
class parallelogram : public Quadrangle {
public:
	parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B) {
		name = "Параллелограм";
	}
};
//ромб(все стороны равны, углы A, C и B, D попарно равны).
class rhombus : public Quadrangle{
public:
	rhombus(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B) {
		name = "Ромб";
	}
};
//квадрат (все стороны равны, все углы равны 90);
class square : public rhombus {
public:
	square(double a) : rhombus(a, 90, 90) {
		name = "Квадрат";
	}
};

///////////////////////////////////////////
int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	triangle triangle(15, 20, 33, 55, 64, 44); //треугольник
	right_triangle right_triangle(15, 20, 33, 55, 44); //прямоугольный треугольник (угол C всегда равен 90);
	isosceles_triangle isosceles_triangle(15, 20, 33, 26); //равнобедренный треугольник(стороны a и c равны, углы A и C равны);
	estimated_triangle estimated_triangle(50);//равносторонний треугольник (все стороны равны, все углы равны 60);
	Quadrangle quandrangle(10, 20, 30, 40, 60, 90, 90, 90); //прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
	rectangle rectangle(20,50); //прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
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