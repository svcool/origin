#include <iostream>

using namespace std;

template<class T>
class arrTable {
	T** arr = nullptr;
	unsigned row{};
	unsigned col{};

public:
	arrTable(unsigned row_, unsigned col_) : row(row_), col(col_) {
		arr = new T * [row];
		for (unsigned i= 0; i < row; i++) {
			arr[i] = new T[col]{0};
		}
	}
	//печать массива
	void print() {
		cout << "Вывод массива: \n";
		for (unsigned i = 0; i < row; i++) {
			for (unsigned j = 0; j < col; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
	//переопределение оператора <<
	friend std::ostream& operator << (std::ostream& stream, const arrTable& arr) {
		stream << arr[row][col];
		return stream;
	}

	T* operator [] (unsigned i) {
		return arr[i];
	}
	//константная версия??????????????
	const T* operator [] (unsigned i) const {
		return arr[i];
	}

	void size() const{
		cout << "Таблица: " << row << " x " << col;
	}

	~arrTable() {
	for (unsigned i = 0; i < row; i++) {
		delete[] arr[i];
		
	}
	delete[] arr;
	arr = nullptr;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	arrTable<int> arr(2, 5);
	arr[1][3] = 6;
	cout << "Вывод arr[1][3]: " << arr[1][3] << "\n";
	arr.print();
	cout << "\n";
	arr.size();
}