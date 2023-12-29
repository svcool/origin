#include <iostream>
using namespace std;

void print(int* arr, int size) {
	cout << "\n";
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

};
int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	int arr1[] = { 1, 3, 6, 5, 9, 8 };
	int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	const int n1 = sizeof(arr1) / sizeof(arr1[0]);
	const int n2 = sizeof(arr2) / sizeof(arr2[0]);
	const int n3 = sizeof(arr3) / sizeof(*arr3);

	cout << "Исходный массив: ";
	for (int x : arr1) {
		cout << x << " ";
	}
	print(arr1, n1);
	print(arr2, n2);
	print(arr3, n3);


	string command{};
	
	do {


	
	} while (command == "exit");

	return 0;
}