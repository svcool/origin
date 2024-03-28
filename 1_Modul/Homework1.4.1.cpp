#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); // настраиваем кодировку консоли
	int i{};
	int sum{};
	//while (i != 0) {
	//	std::cout << "Введите целое число или число '0', чтобы закончить:\n";
	//	std::cin >> i;
	//	sum += i;
	//}

	do {
		std::cout << "Введите целое число или число '0', чтобы закончить:\n";
		std::cin >> i;
		sum += i;
	} while (i != 0);
	std::cout << "Сумма: " << sum << std::endl;
	return(0);
}