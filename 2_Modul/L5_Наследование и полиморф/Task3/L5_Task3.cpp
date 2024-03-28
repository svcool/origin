#include <iostream>

class figure {
protected:
	std::string name{};
	int count{};
	bool f_check{ false }; //переменная, чтобы не вызывалась повторно функция check()
virtual bool check() {
		if (count == 0) return f_check = true;
		else return f_check = false;
	}
public:
		figure(std::string name = "Фигура", int count = 0 ) : name(name), count(count) {
	}
	virtual void print_info() {
		std::cout << name << ":" << std::endl;
		if (f_check == true) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Не правильная" << std::endl; }
		std::cout << "Количество сторон: " << count << std::endl;
	}
};
/// <summary>
/// Треугольник
/// </summary>
class triangle : public figure {
protected:
	double a{}, b{}, c{};
	double A{}, B{}, C{};
	//треугольник(стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
	bool check() override {
		if ((A + B + C) == 180 && a > 0 && b > 0 && c > 0) { count = 3;  return f_check = true; }
	else {
			if (a > 0 && b > 0 && c > 0) { count = 3; }
			else if ((a > 0 && b > 0 && c == 0) || (a > 0 && b == 0 && c > 0) || (a == 0 && b > 0 && c > 0)) { count = 2; }
			else if ((a > 0 && b == 0 && c == 0) || (a == 0 && b == 0 && c > 0) || (a == 0 && b > 0 && c == 0)) { count = 1; }
			else count = 0; 
		return  f_check = false;
	}
}
public:
	triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {
		name = "Треугольник";
		check();
	}
	void print_info() {
		std::cout << std::endl;
		figure::print_info();
		std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << std::endl;
	}
	};

//прямоугольный треугольник (угол C всегда равен 90);
class right_triangle : public triangle {
public:
	right_triangle(double a, double b, double c, double A, double B, double C) : triangle(a, b, c, A, B, C) {
		name = "Прямоугольный треугольник";
		if (f_check == true) { c_check(); } // проверка условия родителя на правильность фигуры, если false условие производного класса не проверяем
	}
	bool c_check() {
		if (C == 90) { return f_check = true; }
		else { return f_check = false; }
	}
};
//равнобедренный треугольник(стороны a и c равны, углы A и C равны);
class isosceles_triangle : public triangle {
public:
	isosceles_triangle(double a, double b, double c, double A, double B, double C) : triangle(a, b, c, A, B, C) {
		name = "Равнобедренный треугольник";
		if (f_check == true) { c_check(); } // проверка условия родителя на правильность фигуры, если false условие производного класса не проверяем
	}
	bool c_check() {
		if (a == c && A == C) { return f_check = true; }
		else { return f_check = false; }
	}
};
//равносторонний треугольник (все стороны равны, все углы равны 60);
class estimated_triangle : public triangle {
public:
	estimated_triangle(double a, double b, double c, double A, double B, double C) : triangle(a, b, c, A, B, C) {
		name = "Равносторониий треугольник";
		if (f_check == true) { c_check(); } // проверка условия родителя на правильность фигуры, если false условие производного класса не проверяем
	}
	bool c_check() {
		if (a == b && b == c && A == 60 && B == 60 && C == 60) { return f_check = true; }
		else { return f_check = false; }
	}
};

/// <summary>
/// четырехугольник
/// </summary>
class Quadrangle : public figure {
protected:
	double a{}, b{}, c{}, d{}; //стороны
	double A{}, B{}, C{}, D{}; //углы
	//четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
	bool check() override {
		if ((A + B + C + D) == 360 && a > 0 && b > 0 && c > 0 && d > 0) { 
			count = 4;  
			return f_check = true; 
		}
		else {
			// проверка количества сторон исключая нулевые стороны
			if (a > 0 && b > 0 && c > 0 && d > 0) { count = 4; }
			else if ((a > 0 && b > 0 && c > 0 && d == 0) || (a > 0 && b > 0 && c == 0 && d > 0) || (a > 0 && b == 0 && c > 0 && d > 0) || (a == 0 && b > 0 && c > 0 && d > 0)) { count = 3; }
			else if ((a > 0 && b > 0 && c == 0 && d == 0) || (a > 0 && b== 0 && c == 0 && d > 0) || (a == 0 && b == 0 && c > 0 && d > 0) || (a == 0 && b > 0 && c > 0 && d == 0) 
				|| (a == 0 && b > 0 && c == 0 && d > 0) || (a > 0 && b == 0 && c > 0 && d == 0)) { count = 2; }
			else if ((a > 0 && b == 0 && c == 0 && d == 0) || (a == 0 && b == 0 && c == 0 && d > 0) || (a == 0 && b > 0 && c == 0 && d == 0) || (a == 0 && b == 0 && c > 0 && d == 0)) { count = 1; }
			else count = 0;
			return  f_check = false;
		}
	}
public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
		name = "Четырехугольник";
		check();
	}
	void print_info() override {
		std::cout << std::endl;
		figure::print_info();
		std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
	}
};

//прямоугольник(стороны a, c и b, d попарно равны, все углы равны 90);
class rectangle : public Quadrangle
{
public:
	rectangle(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D) {
		name = "Прямоугольник";
		if (f_check == true) { c_check(); } // проверка условия родителя на правильность фигуры, если false условие производного класса не проверяем
	}
	bool c_check() {
		if ((a == c && b == d) && A == 90 && B == 90 && C == 90 && D == 90) { return f_check = true; }
		else { return f_check = false; }
	}
 
};

//параллелограмм(стороны a, c и b, d попарно равны, углы A, C и B, D попарно равны);
class parallelogram : public Quadrangle {
public:
	parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D) {
		name = "Параллелограм";
		if (f_check == true) { c_check(); } // проверка условия родителя на правильность фигуры, если false условие производного класса не проверяем
	}
	bool c_check() {
		if ((a == c && b == d) && A == C && B == D) { return f_check = true; }
		else { return f_check = false; }
	}
};
//ромб(все стороны равны, углы A, C и B, D попарно равны).
class rhombus : public Quadrangle {
public:
	rhombus(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D) {
		name = "Ромб";
		if (f_check == true) { c_check(); } // проверка условия родителя на правильность фигуры, если false условие производного класса не проверяем
	}
	bool c_check() {
		if (a == b && b == c && c == d &&  A == C && B == D) { return f_check = true; }
		else { return f_check = false; }
	}
};

//квадрат (все стороны равны, все углы равны 90);
class square : public rhombus {
public:
	square(double a, double b, double c, double d, double A, double B, double C, double D) : rhombus(a, b, c, d, A, B, C, D) {
		name = "Квадрат";
		if (f_check == true) { c_check(); } // проверка условия родителя на правильность фигуры, если false условие производного класса не проверяем
	}
	bool c_check() {
		//достаточно проверки углов, равенство сторон проверено в ромбе
		if (A == 90 && B == 90 && C == 90 && D == 90) { return f_check = true; } 
		else { return f_check = false; }
	}
};


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