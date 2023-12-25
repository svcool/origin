#include <iostream>
using namespace std;
void count_sort(int* arr, int size) {
	int counts[10]{};
	for (int i = 0; i < size; ++i) {
		++counts[arr[i]];
	}
	int c = 0;
	for (int i = 0; i < size; ++i) {
		while (counts[c] = 0)
			c += 1;
		arr[i] = c;
		counts[c] -= 1;
	}
}
void CountingSort(int a[], int n)
{
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int* c = new int[max + 1 - min];
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i] - min] = c[a[i] - min] + 1;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (c[j - min] != 0) {
			a[i] = j;
			c[j - min]--;
			i++;
		}
	}
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
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "Russian");

	const int n1 = 10, n2 = 15, n3 = 18;
	int arr1[n1]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arr2[n2]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr3[n3]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	
	print(arr1, n1);
	
	print(arr2, n2);
	print(arr3, n3);


}