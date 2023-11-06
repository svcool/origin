#include <iostream>

class figure {

protected:
	std::string name;
	int count = 0;
	bool check = false;
	//фигура (количество сторон равно 0);
	virtual bool Check() {
		if (count == 0) { return true; }
		else { return false; }
	}

public:
	virtual void print_info() { std::cout << name; }
	void print_info() {
		std::cout << std::endl;
		std::cout << name << ":" << std::endl;
		if (Check()) {
			std::cout << "Правильная" << std::endl;
		}
		else { std::cout << "Не правильная" << std::endl;
		}
		std::cout << "Количество сторон" << count << std::endl;
	}
};
//////////////////////////////////////////////
class triangle : public figure {
protected:
	double a{}, b{}, c{};
	double A{}, B{}, C{};
	bool Check() override {
		// треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
		if ((A + B + C) == 180) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {
		name = "Треугольник";
		count = 3;
		check = Check();
	}

	void print_info() override {
		figure::print_info();
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
	//четырёхугольник(стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
	virtual bool Check() {
		if ((A + B + C) == 360){
			return true;
		}
		else {
			return false;
		}
		if (a == c && b == d)
		{
			return true;
		}
		else
		{
			return false;
		}
		if (a == b && b == c && c == d)
		{
			return true;
		}
		else
		{
			return false;
		}
		if (A == 90 && B == 90 && C == 90 && D == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
		if (A == C && B == D)
		{
			return true;
		}
		else
		{
			return false;
		}


	}
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
protected:
	//прямоугольный треугольник (угол C всегда равен 90);
	bool Check() override {
		if (triangle::Check() && (C == 90)) {
			return true;
		}
		else {
		return false;
		}
	}

public:
	right_triangle(double a, double b, double c, double A, double B) : triangle(a, b, c, A, B, 90) {
		triangle::name = "Прямоугольный треугольник";
	}
};
//равнобедренный треугольник(стороны a и c равны, углы A и C равны);
class isosceles_triangle : public triangle {
protected:
	bool Check() override
	{
		if (triangle::Check() && (a == c && A == C))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	isosceles_triangle(double a, double b, double A, double B) : triangle(a, b, a, A, B, A) {
		triangle::name = "Равнобедренный треугольник";
	}
};
//равносторонний треугольник (все стороны равны, все углы равны 60);
class estimated_triangle : public triangle {
protected:
	bool Check()
	{
		if (a == b && b == c && (A == 60) && B == 60 && C == 60)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
public:
	estimated_triangle(double a) : triangle(a, a, a, 60, 60, 60) {
		triangle::name = "Равносторониий треугольник";
	}
};
//прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
class rectangle : public Quadrangle
{
protected:
	bool Check() override
	{
		if (Quadrangle::Check() && Quadrangle::CheckSides1() && Quadrangle::CheckAngles1())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
		Quadrangle::name = "Прямоугольник";
	}
};

//квадрат (все стороны равны, все углы равны 90);
class square : public Quadrangle {
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides2() && Quadrangle::CheckAngles1()) { return true; }
		else { return false; }
	}

public:
	square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
		Quadrangle::name = "Квдрат";
	}
};
//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
class parallelogram : public Quadrangle {
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides1() && Quadrangle::CheckAngles2()) { return true; }
		else { return false; }
	}


public:
	parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B) {
		Quadrangle::name = "Параллелограм";
	}
};
//ромб(все стороны равны, углы A, C и B, D попарно равны).
class rhombus : public Quadrangle {
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides2() && Quadrangle::CheckAngles2()) { return true; }
		else { return false; }
	}
public:
	rhombus(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B) {
		Quadrangle::name = "Ромб";
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

	figure* f_square = &square;
	f_square->print_info();

	figure* f_parallelogram = &parallelogram;
	f_parallelogram->print_info();

	figure* f_rhombus = &rhombus;
	f_rhombus->print_info();

}