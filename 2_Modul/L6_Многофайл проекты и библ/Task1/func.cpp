double pow(double x, double y) {
	double result{1};
	for (int i = 1; i <= y; i++) {
		result = result * x;
	}
	return result;
}
double add(double x, double y) {
	return x + y;
};
double subtraction(double x, double y) {
	return x - y;
};
double multiplication(double x, double y) {
	return x * y;
};
double division(double x, double y) {
	return x / y;
}