#include <iostream>
#include <fstream>

int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream f("in1.txt");
	if (f.is_open()) {
		int s{};
		int size{};
		f >> s; // читаем размер массива
		size = s;
		int* arr = new int[size];
		for (int i{}; i < size; i++) {
			f >> s; // читаем данные массива
			arr[i] = s;
		}

		for (int i = (size - 1); i >= 0; i--) {
			std::cout << arr[i] << " ";
		}
		delete[] arr;
		f.close();
	}
	else std::cout << "Error openning file";
	return 0;
}