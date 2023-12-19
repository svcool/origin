#include <iostream>

int main()
{
	//setlocale(LC_ALL, "Russian");
	//system("chcp 1251"); // настраиваем кодировку консоли
	int arr[10];
	int i{ 0 };
	// std::size(arr) не работает в ripl - показывает размер массива
	int sizearr = sizeof(arr) / sizeof(arr[0]);
	//формируем массив
	for (int i{}; i < sizearr; i++) {
		arr[i] = i * 2 + 4;
	}


	//выводим массив
	for (int i{}; i < sizearr; i++) {
		std::cout << arr[i];
		(i == sizearr - 1) ? (std::cout << " ") : (std::cout << ", ");
	}
	std::cout << std::endl;
	return(0);
}