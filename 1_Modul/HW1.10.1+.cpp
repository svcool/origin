#include <iostream>

void filling_arr(int*, int);
void output_arr(int*, int);
void delete_arr(int*, int);
int* create_arr(int&);
int main() {
	int size{};
	int* arr = create_arr(size);
	filling_arr(arr, size); // заполнение массива
	output_arr(arr, size); // вывод массива
	delete_arr(arr, size); // очищаем память
}

int* create_arr(int& size) {
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	return new int[size];
}


void filling_arr(int* arr, int s) {
	for (int i = 0; i < s; i++) {
	int a{};
	std::cout << "arr[" << i << "] = ";
	std::cin >> a;
	arr[i] = a;
	}

}

void output_arr(int* arr, int s) {
	for (int i = 0; i < s; i++) {
		if (i == 0) { std::cout << "The entered array: " << arr[i]; }
		else { std::cout << " " << arr[i]; }
	}
	std::cout << std::endl;
}

void delete_arr (int* arr, int s) {
	delete[] arr;
}