#include <iostream>
int function(int* arr, const int size, int number) {
	int result{};
	int left = 0;
	int right = size - 1;
	while (true) {
		int middle = (left + right )/ 2;
		if (arr[middle] > number) {
			result = size - middle;
			right = middle - 1; 
		}
		else if (arr[middle] <= number) {
			left = middle + 1;
		}
		if (left > right) return result;
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int number = 0;
	const int size = 9;
	int arr[9] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
	while (true) {
		std::cout << "Введите точку отсчёта: "; std::cin >> number;
		std::cout << "Количество элементов в массиве больших, чем " << number << ": " << function(arr, size, number) << std::endl;
	}

}