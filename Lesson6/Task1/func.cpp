#include <iostream>
double pow(double x, double y) {
	double result{1};
	for (int i = 1; i <= y; i++) {
		result = result * x;
	}
	return std::cout << x << " в степени " << y << "=" << result << std::endl;;
}

double add(double x, double y) {
	return std::cout << "Сумма" << x << " и " << y << "=" << x + y << std::endl;
};
double subtraction(double x, double y) {
	return std::cout  << "Разность" << x << " и " << y << "=" << x - y << std::endl;
};
double multiplication(double x, double y) {
	return std::cout << "Произведение" << x << " и " << y << "=" << x * y << std::endl;;
};
double division(double x, double y) {
	return std::cout << "Деление" << x << " и " << y << "=" << x / y << std::endl;;
}