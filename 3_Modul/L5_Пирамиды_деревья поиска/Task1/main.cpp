#include <iostream>
using namespace std;
//class Piramida {
//	int size;
//	int* arr;
//public:
//	Piramida(int* arr, int size) :arr(arr), size(size){}
//
//	int root() {
//		return arr[0];
//	}
//
//	int from_index(int index) {
//		return arr[index];
//	}
//
//	int left_index(int parrent_index) {
//		return 2 * parrent_index + 1;
//	}
//
//	int right_index(int parrent_index) {
//		return 2 * parrent_index + 2;
//	}
//	int parrent_index(int child_index) {
//		return (child_index - 1) / 2;
//	}
//	
//	
//};

void print_pyramid(int* arr, int size) {
	int x{}; //расчетный индекс родителя
	int y{2}; //счетчик уровней
	int z{1}; //номер уровня дерева
	cout << "\nПирамида: ";
	for (int i = 0; i < size; ++i) {
//вывод корня и подсчет следующих уровней
		if (i == 0) {
			cout << "\n" << 0 << " root " << arr[0];
			continue;
		}
		else if (y == 0) { 
			++z; 
			y = z * z;
		}
//четный - правый, нечетный - левый
		if (i % 2 == 0) {
			x = (i - 2) / 2;
			cout << "\n" << z << " " << "right" << "(" << arr[x] << ") " << arr[i];
		}
		else {
			x = (i - 1) / 2;
			cout << "\n" << z << " " << "left" << "(" << arr[x] << ") " << arr[i];
		}
		y--;
	}
	cout << "\n";
};
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
	int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
	int arr3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
	const int n1 = sizeof(arr1) / sizeof(arr1[0]);
	const int n2 = sizeof(arr2) / sizeof(arr2[0]);
	const int n3 = sizeof(arr3) / sizeof(*arr3);

	print(arr1, n1);
	print_pyramid(arr1, n1);
	print(arr2, n2);
	print_pyramid(arr2, n2);
	print(arr2, n2);
	print_pyramid(arr3, n3);

}