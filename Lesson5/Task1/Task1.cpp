#include <iostream>

class figure {
private:
	int side_count;
	std::string name;
protected:

	figure(int side_count, std::string name) {
		this->side_count = side_count;
		this->name = name;
	}

public:

	//тоже работает
	figure() {
		side_count = 0;
		name = "Фигура";
	}
	//и так работает
	//figure() : figure(0, "Фигура11") {};

	int get_sides_count() {
		return side_count;
	}

	std::string get_name() {
		return name;
	}

};

class triangle : public figure {
public:
	triangle() : figure(3, "Треугольник") {};
};

class Quadrangle : public figure {
public:
	Quadrangle() : figure(4, "Квадрат") {};

};



int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	figure f;
	triangle tr;
	Quadrangle qv;
	std::cout << "Количество сторон:" << std::endl;
	std::cout << f.get_name() << ": " << f.get_sides_count() << std::endl;
	std::cout << tr.get_name() << ":  " << tr.get_sides_count() << std::endl;
	std::cout << qv.get_name() << ":  " << qv.get_sides_count() << std::endl;


}