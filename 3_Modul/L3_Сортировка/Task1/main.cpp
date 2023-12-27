#include <iostream>
using namespace std;
void merge(int* arr, int size, int* arr_l, int size_left, int* arr_r, int size_right);
void merge_sort(int* arr, int size);
void merge_sort(int* arr, int size) {
	//делим массив на два массива и заполняем данными
	if (size > 1) {
		int size_left = size / 2;
		int size_right = size - size_left;
		int* arr_l = new int[size_left];
		int* arr_r = new int[size_right];
		for (int i = 0; i < size; i++) {
			if (i < size_left) {
				arr_l[i] = arr[i];
			}
			else {
				arr_r[i - size_left] = arr[i];
			}
		}
		merge_sort(arr_l, size_left);
		merge_sort(arr_r, size_right);
		merge(arr, size, arr_l, size_left, arr_r, size_right);
		delete[] arr_l;
		delete[] arr_r;
	}
}

void merge(int* arr, int size, int* arr_l, int size_left, int* arr_r, int size_right) {
	//сортировка
	for (int i = 0; i < size_left;++i) {
		cout << arr_l[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < size_right; ++i) {
		cout << arr_r[i] << " ";
	}
	cout << "\n";
	int i = 0, j = 0;
	while (i < size_left || j < size_right) {
		if (i < size_left && j < size_right) {
			if (arr_l[i] <= arr_r[j]) {
				arr[i + j] = arr_l[i];
				i++;
			}
			else {
				arr[i + j] = arr_r[j];
				j++;
			}
		}
		else if (i < size_left) {
			arr[i + j] = arr_l[i];
			i++;
		}
		else if (j < size_right) {
			arr[i + j] = arr_r[j];
			j++;
		}
	}
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";

}
void print(int* arr, int size) {
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	merge_sort(arr, size);
	cout << "Отсортированный массив:: ";
	
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	const int n1 = 10, n2 = 15, n3 = 18;
	int arr1[n1]{3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arr2[n2]{88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
	int arr3[n3]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	//массив с середины другого массива
	//int* arr11 = &arr1[5];
	//for (int i = 0; i < 10; ++i) {
	//	cout << arr11[i] << "  ";
	//}

	print(arr1, n1);
	print(arr2, n2);
	print(arr3, n3);

	
}