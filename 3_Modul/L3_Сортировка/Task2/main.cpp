#include <iostream>
using namespace std;
void quick_sort(int* arr, int size) {
    if (size == 1) return;
    int left = 0;
    int right = size - 1;
    int p = size / 2;
    int pivot = arr[p];
    while (left <= right) {
        while (arr[left] < pivot) {
            left += 1;
        }
        while (arr[right] > pivot) {
            right -= 1;
        }
        if (left >= right) {
            left = left;
        }
        else {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left += 1;
            right -= 1;
        }
    }
   if (right > 0) quick_sort(arr, right + 1);
   //     
   if(left < size) quick_sort(arr, size - 1);

}

void print(int* arr, int size) {
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	quick_sort(arr, size);
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
    quick_sort(arr1, n1);
	print(arr1, n1);
	//print(arr2, n2);
	//print(arr3, n3);


}