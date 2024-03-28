#include <iostream>
using namespace std;
void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	cout << "Динамический массив: ";
	for (int i = 0; i < logical_size; ++i) {
		cout << arr[i] << " ";
	}
	for (int i = logical_size; i < actual_size; ++i) {
		cout << "_" << " ";
	}

}
	
int main() {
	setlocale(LC_ALL, "Russian");

	int size_fact{};
	int size_log{};

	do {
		cout << "Введите фактичеcкий размер массива: "; cin >> size_fact;
		cout << "Введите логический размер массива: "; cin >> size_log;
		if (size_log > size_fact) {
			cout << "Ошибка!Логический размер массива не может превышать фактический! \n";
			continue;
		}
		break;
	} while (true);


	int* arr = new int[size_fact] {}; //создаем массив

	for (int i = 0; i < size_log; ++i) {
		cout << "Введите arr[" << i << "] : ";
		cin >> arr[i];
	}

	
	print_dynamic_array(arr, size_log, size_fact);

	delete[] arr;
	arr = nullptr;
}