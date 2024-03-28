#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); // настраиваем кодировку консоли 
replace:
	int n1 = 0, n2 = 0, n3 = 0, max = 0, mid = 0, low = 0;
	std::cout << "¬ведите первое число: ";
	std::cin >> n1;
	std::cout << "¬ведите второе число: ";
	std::cin >> n2;
	std::cout << "¬ведите третье число: ";
	std::cin >> n3;

	(n1 > n2) ? (n1 > n3) ? (max = n1, (n2 > n3) ? (mid = n2, low = n3) : (mid = n3, low = n2)) : (max = n3, mid = n1, low = n2) :
		(n2 > n3) ? (max = n2, (n1 > n3) ? (mid = n1, low = n3) : (mid = n3, low = n1)) : (max = n3, mid = n2, low = n1);

	std::cout << "–езультат: " << max << ", " << mid << ", " << low << std::endl;
	goto replace;
	return 0;
}