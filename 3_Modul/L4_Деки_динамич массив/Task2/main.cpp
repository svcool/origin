#include <iostream>
using namespace std;

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	for (int i = 0; i < logical_size; ++i) {
		cout << arr[i] << " ";
	}
	for (int i = logical_size; i < actual_size; ++i) {
		cout << "_" << " ";
	}
	cout << "\n";
}
void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int add) {
	++logical_size;
	if (logical_size <= actual_size) { 
			arr[logical_size - 1] = add; 
	}
	else {
		actual_size *= 2;
		int* arr_add = new int[actual_size] {};
		for (int i = 0; i < logical_size - 1; ++i) {
			arr_add[i] = arr[i];
		}
		arr_add[logical_size - 1] = add;
		delete[] arr;
		arr = arr_add;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");

	int size_fact{};
	int size_log{};
	int add{};
	
	do {
		cout << "Введите фактичеcкий размер массива: "; cin >> size_fact;
		cout << "Введите логический размер массива: "; cin >> size_log;
		if (size_log > size_fact) {
			cout << "Ошибка!Логический размер массива не может превышать фактический! \n";
			continue;
		}
		break;
	} while (true);
	//создание массива

	int* arr = new int[size_fact] {}; 
	for (int i = 0; i < size_log; ++i) {
		cout << "Введите arr[" << i << "] : ";
		cin >> arr[i];
	}
	cout << "Динамический массив: ";
	print_dynamic_array(arr, size_log, size_fact);
	
	//Добавление элемента
	do {
		cout << "Введите элемент для добавления: "; cin >> add;
		if (add == 0) break;
		append_to_dynamic_array(arr, size_log, size_fact, add);
		cout << "Динамический массив: ";
		print_dynamic_array(arr, size_log, size_fact);
	} while (true);
	//Завершение
	cout << "Спасибо!Ваш массив: ";
	print_dynamic_array(arr, size_log, size_fact);
	delete[] arr;
	arr = nullptr;
}
//void foo(int** ptr) {
//	if (*ptr == 0)
//		*ptr = new int(123);
//}
//
//int main() {
//	int* ptr = 0;
//
//	foo(&ptr);
//
//	std::cout << *ptr << std::endl;
//
//	return 0;
//}
//void foo(int*& ptr) {
//	if (ptr == 0)
//		ptr = new int(123);
//}
//
//int main() {
//	int* ptr = 0;
//
//	foo(ptr);
//
//	std::cout << *ptr << std::endl;
//
//	return 0;
//}