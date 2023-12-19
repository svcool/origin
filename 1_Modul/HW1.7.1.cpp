#include <iostream>
#include <iomanip>
int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int aint{};
	short ashort{};
	long along{};
	long long a2long{};
	float afloat{};
	double adouble{};
	long double aldouble{};
	bool abool{};
	std::cout << std::setw(14) << "int: " << std::setw(18) << &aint << std::setw(3) << sizeof(aint) << std::endl;
	std::cout << std::setw(14) << "short: " << std::setw(18) << &ashort << std::setw(3) << sizeof(ashort) << std::endl;
	std::cout << std::setw(14) << "long: " << std::setw(18) << &along << std::setw(3) << sizeof(along) << std::endl;
	std::cout << std::setw(14) << "long long: " << std::setw(18) << &a2long << std::setw(3) << sizeof(a2long) << std::endl;
	std::cout << std::setw(14) << "float: " << std::setw(18) << &afloat << std::setw(3) << sizeof(afloat) << std::endl;
	std::cout << std::setw(14) << "double: " << std::setw(18) << &adouble << std::setw(3) << sizeof(adouble) << std::endl;
	std::cout << std::setw(14) << "long double: " << std::setw(18) << &aldouble << std::setw(3) << sizeof(aldouble) << std::endl;
	std::cout << std::setw(14) << "bool: " << std::setw(18) << &abool << std::setw(3) << sizeof(abool) << std::endl;
	return 0;


}