#include <iostream>
//#include<array>
using namespace std;
 void count_sort(int* arr, int size){
	int* counts = new int[size]{};
	for (int i = 0; i < size; ++i) {
		counts[arr[i]-10]+=1;
	}
	int c = 0;
	for (int i = 0; i < size; ++i) {
		while (counts[i] != 0) {
			arr[c] = i + 10;
			c += 1;
			counts[i] -= 1;
		}
	}
	delete[] counts;
}


void print(int* arr, int size) {
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
count_sort(arr, size);
	cout << "Отсортированный массив:: ";

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, "Russian");

	int arr1[]{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
	int arr2[]{ 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
	int arr3[]{ 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
	
	const int n1 = sizeof(arr1) / sizeof(*arr1);
	const int n2 = sizeof(arr2) / sizeof(*arr2);
	const int n3 = end(arr3) - begin(arr3);
	
	print(arr1, n1);
	print(arr2, n2);
	print(arr3, n3);
}