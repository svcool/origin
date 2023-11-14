#include <iostream>
#include <fstream>

void filing_arr(int* arr, int size, std::ifstream& in); //заполнение массива из файла in.txt

void out_arr(int* arr, int size_arr, std::ofstream& out); // вывод массива в файл out.txt

void offset_arr(int* arr, int size_arr, int x); // смещение массива "-1" - влево; "1" - вправо

int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream in("in.txt"); //открываем файл
	//проверка на открытие файла
	if (!in.is_open()) {
		std::cout << "Ошибка открытия файла" << std::endl;
		return 0;
	}
	int size1{}, size2{}, f{};
	in >> size1;
	int* arr1 = new int[size1];
	filing_arr(arr1, size1, in); //заполняем массив
	in >> size2;
	int* arr2 = new int[size2];
	filing_arr(arr2, size2, in); //заполняем массив

	offset_arr(arr1, size1, -1);
	offset_arr(arr2, size2, 1);
	in.close(); // закрыть файл
	std::ofstream out("out.txt");
	if (!out.is_open()) {
		std::cout << "Ошибка открытия файла" << std::endl;
		return 0;
	}
	out_arr(arr2, size2, out); // выводим массив в файл
	out_arr(arr1, size1, out); // выводим массив в файл


	delete[] arr1;
	delete[] arr2;
	out.close();

	return 0;
}
//заполнение массива из файла in.txt
void filing_arr(int* arr, int size, std::ifstream& in) {
	int data{};
	for (int i{}; i < size; i++) {
		in >> data; // читаем данные из массива
		arr[i] = static_cast<int>(data);
	}
}
// вывод массива в файл out.txt
void out_arr(int* arr, int size_arr, std::ofstream& out) {
	out << size_arr << "\n";
	for (int i{}; i < size_arr; i++) {
		out << arr[i] << " ";
	}
	out << "\n";
}
//смещение массива "-1" - влево; "1" - вправо
void offset_arr(int* arr, int size_arr, int x) {
	int temp{};
	if (x == -1) {
		temp = arr[0];
		for (int i{}; i < size_arr - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[size_arr - 1] = temp;
	}
	if (x == 1) {
		temp = arr[size_arr - 1];
		for (int i{ size_arr - 1 }; i >= 1; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = temp;
	}
}