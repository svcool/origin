#include <iostream>
using namespace std;

class Pyramid {
	int* arr;
	int size;
public:
	Pyramid(int* arr, int size) :arr(arr), size(size) {}

	int unsigned index_actual{};

int level(int index) {
	int level{1};
	if (index == 0) return 0;
	else if (index <= 2) return 1;
	while (true) {
		if (index % 2 == 0) {
				index = (index - 2) / 2;
				if (index >= 1) ++level;
				else break;
		}
		else {
				index = (index - 1) / 2;
				if (index >= 1) ++level;
				else break;
			}
	}
	return level;
}
void up() {
	if (index_actual == 0) cout << "Ошибка! Отсутствует родитель\n";
	else if (index_actual % 2 == 0) {
		index_actual = (index_actual - 2) / 2;
		cout << "OK\n";
	}
	else {
		index_actual = (index_actual - 1) / 2;
		cout << "OK\n";
	}
}

void left() {
	int index{};
	index = 2 * index_actual + 1;
	if (index > size - 1) {
		cout << "Ошибка! Отсутствует левый потомок\n";
	}
	else {
		index_actual = 2 * index_actual + 1;
		cout << "OK\n";
	}
}

void right() {
	int index{};
	index = 2 * index_actual + 2;
	if (index > size - 1) {
		cout << "Ошибка! Отсутствует правый потомок\n";
	}
	else {
		index_actual = index;
		cout << "OK\n";
	}

}
void where_iam() {
	where_iam(index_actual);
}
void where_iam(int index) {
	int x{};
			if (index == 0) {
				cout << 0 << " root " << arr[0];
			}
			//четный - правый, нечетный - левый
			else if (index % 2 == 0) {
				x = (index - 2) / 2;
				cout << level(index) << " " << "right" << "(" << arr[x] << ") " << arr[index];
			}
			else {
				x = (index - 1) / 2;
				cout << level(index) << " " << "left" << "(" << arr[x] << ") " << arr[index];
			}
}


void print_pyramid() {
	cout << "\nПирамида: ";
	for (int i = 0; i < size; ++i) {
		cout << "\n";
		where_iam(i);
	}
	cout << "\n";
}

void print() {
	cout << "\n";
	cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
};

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	int arr1[] = { 1, 3, 6, 5, 9, 8 };
	int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4, 94, 67, 18, 44, 55, 12, 6, 42 };
	const int n1 = sizeof(arr1) / sizeof(arr1[0]);
	const int n2 = sizeof(arr2) / sizeof(arr2[0]);
	const int n3 = sizeof(arr3) / sizeof(*arr3);
	
	Pyramid pyramid(arr3, n3);

	pyramid.print();
	pyramid.print_pyramid();	

	string command{};
	pyramid.index_actual = 0;
	do {
		cout << "\nВы находитесь здесь: ";
		pyramid.where_iam();
		cout << "\nВведите команду(up, left, right, exit): "; cin >> command;
		
		if (command.compare("up") == 0) {
			pyramid.up();
			continue;
		}
		if (command.compare("left") == 0) {
			pyramid.left();
			continue;
		}
		if (command.compare("right") == 0) {
			pyramid.right(); 
			continue;
		}
		if (command.compare("exit") == 0) {
			cout << "OK. Досвидания"; 
			break;
		}
		cout << "Нет такой команды\n";
			
	} while (true);

	return 0;
}