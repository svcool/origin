#include <iostream>
#include <fstream>

int main() {
	std::ifstream f("in3.txt");
	//проверка открытия файла
	if (f.is_open()) {
		int col{}, row{};
		f >> row;
		f >> col;
		// создать дин. массив
		int** arr = new int* [row];
		for (int i{}; i < row; i++) {
			arr[i] = new int[col];
		}
		//читаем файл в массив
		for (int i{}; i < row; i++) {
			for (int j{}; j < col; j++) {
				f >> arr[i][j];
			}
		}
		//выводим на консоль в обратном порядке
		for (int i{}; i < row; i++) {
			for (int j = (col - 1); j >= 0; j--) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << std::endl;
		}

		//удалить массив из памяти
			for (int i{}; i < row; i++) {
				delete[] arr[i];
		}
			delete[] arr;
		//закрыть файл
			f.close(); 
	}

	else std::cout << "Fail to open file!" << std::endl;


		return 0;
	}