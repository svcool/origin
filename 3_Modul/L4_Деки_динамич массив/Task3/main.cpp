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
void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size, string del) {
	--logical_size;
	if (logical_size > actual_size / 3) {
		cout << actual_size / 3 << "\n";
		for (int i = 0; i <= logical_size + 1; ++i) {
			arr[i] = arr[i + 1];
		}
	}
	if (logical_size <= actual_size / 3 && logical_size != 0) {
		actual_size = actual_size / 3;
		cout << actual_size << "\n";
		int* arr_add = new int[actual_size] {};
		for (int i = 0; i < logical_size + 1; ++i) {
			arr_add[i] = arr[i + 1];
		}
		delete[] arr;
		arr = arr_add;
	}
	//обнуляем последний элемент в единичном массиве
	if (logical_size == 0) arr[0] = 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int size_fact{};
	int size_log{};
	std::string del{};

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
		cout << "Удалить первый элемент: "; cin >> del;
		if (del == "нет") {
			cout << "Спасибо!Ваш динамический массив: ";
			print_dynamic_array(arr, size_log, size_fact);
			break;
		}

		 if (del == "да" && size_log == 0) {
			cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!\n";
			break;
		}
		 if (del == "да") {
				 remove_dynamic_array_head(arr, size_log, size_fact, del);
				 cout << "Динамический массив: ";
			 }

		print_dynamic_array(arr, size_log, size_fact);
	} while (true);
	//Завершение
	//Ошибка, если разме массива равен 1, поэтому через условие
	if (size_fact > 1) delete[] arr;
	arr = nullptr;
}