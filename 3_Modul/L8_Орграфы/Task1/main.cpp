#include <iostream>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	ifstream file("input.txt");

	//проверка открытия файла
	if (!file.is_open()) {
		cout << "Fail to open file!" << endl;
		return 0;
	}

	int vertex{};
	file >> vertex;
	//создаем динамический массив смежности орграфа
	int** arr_vertex = new int* [vertex];
	for (int i{}; i < vertex; ++i) {
		arr_vertex[i] = new int[vertex];
	}
	//читаем файл в массив
	for (int i{}; i < vertex; ++i) {
		for (int j{}; j < vertex; ++j) {
			file >> arr_vertex[i][j];
		}
	}
	//выводим графa
		for (int i{}; i < vertex; ++i) {
			for (int j{}; j < vertex; ++j) {
				cout << arr_vertex[i][j] << " ";
			}
			cout << endl;
		}

		cout << "\nТекстовый вид орграфа:\n";

		// вывод доступных вершин графа
		for (int i{}; i < vertex; ++i) {
			int count{};
			cout << i+1 << ": ";
			for (int j{}; j < vertex; ++j) {
				if (arr_vertex[i][j] == 1) {
					cout << j + 1 << " ";
					count++;
				}
			}
			if (count == 0) { cout << "нет"; }
			cout << "\n";
		}

	//удалить массив из памяти
	for (int i{}; i < vertex; ++i) {
		delete[] arr_vertex[i];
	}
	delete[] arr_vertex;

	return 0;
}