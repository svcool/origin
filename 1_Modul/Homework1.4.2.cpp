#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); // настраиваем кодировку консоли
	int i {};
	int sum {};
	std::cout << "Введите целое число: ";
	std::cin >> i;

	while (i != 0) {
		sum += i % 10;
		i = i / 10;
	}
	
	
	std::cout << "Сумма циффр: " << abs(sum) << std::endl;
	return(0);
}