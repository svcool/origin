#include <iostream>
#include <iomanip>

int** create_two_dim_array(int&, int&);
void fill_two_dim_array(int**, int, int);
void print_two_dim_array(int**, int, int);
void delete_two_dim_array(int**, int, int);
int main() {
	int row{}, col{};
	int** arr = create_two_dim_array(row, col);
	fill_two_dim_array(arr, row, col); // заполнение массива
	print_two_dim_array(arr, row ,col); // вывод массива
	delete_two_dim_array(arr, row, col); // очищаем память
	return 0;
}

int** create_two_dim_array(int& row, int& col) {
	std::cout << "Enter the number of lines: ";
	std::cin >> row;
	std::cout << "Enter the number of columns: ";
	std::cin >> col;
	int** arrf = new int* [row];
	for (int i = 0; i < row; i++) {
		arrf[i] = new int[col];
	}
	return arrf;
}
void fill_two_dim_array(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = (j + 1) * (i + 1);
		}
	}

}

//void fill_two_dim_array(int** arr, int row, int col) {
//	std::cout << "Multiplication table:" << std::endl;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			arr[i][j] = j + 1;
//			std::cout << std::setw(10) << arr[i][j] * (i + 1) << " ";
//		}
//		std::cout << std::endl;
//
//	}
//
//}

void print_two_dim_array(int** arr, int row, int col) {
	int count{}, coln = col;
	while (coln != 0) {
		coln = coln / 10;
		count++;
	}
	std::cout << "Multiplication table:" << std::endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << std::setw(count+1) << arr[i][j] << " ";
		}
		std::cout << std::endl;

	}
	
}

void delete_two_dim_array(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;

}