#include <iostream>
//У вашего контейнера должны работать функции :
//
//*at(int index) — доступ к элементу контейнера по индексу;
//*push_back(T value) — размер контейнера неизвестен заранее, вам нужно правильно увеличивать выделенную память;
//*size() — количество элементов в контейнере;
//*capacity() — количество элементов, которое может вместить контейнер до нового выделения памяти.
template<class T>
class my_vector {
	T* arr = nullptr;
	int logic_size{};
	int actual_size{};

	// расширение актуального массива
void arr_add() {
		T* arr_add = new T[actual_size] {};
		for (int i = 0; i < logic_size+1; ++i) {
			arr_add[i] = arr[i];
		}
		delete[] arr;
		arr = arr_add;
	}
public:
	my_vector() {};
	my_vector(int _size) : logic_size(_size) {
		actual_size = logic_size * 2;
		arr = new T[actual_size]{};
	}
	//*at(int index) — доступ к элементу контейнера по индексу;
	int at(int index) {
		if (index < logic_size) { return arr[index]; }
		else { 
			std::cout << "\nIndex is out of range";
			exit(1);
		}
	}
	//*push_back(T value) — размер контейнера неизвестен заранее, вам нужно правильно увеличивать выделенную память;
	void push_back(T value) {
		if (logic_size == 0) {
			actual_size = 10;
			logic_size = 1;
			arr = new T[actual_size];
			arr[0] = value;
		}
		else if (logic_size == actual_size-1) {
			actual_size = actual_size * 2;
			arr[logic_size] = value;
			arr_add();
			logic_size = logic_size + 1;
		}
		else {
			arr[logic_size] = value;
			logic_size = logic_size + 1;
		}
	}
	
	
	//*size() — количество элементов в контейнере;
	int size() {
		return logic_size;
	}
	//*capacity() — количество элементов, которое может вместить контейнер до нового выделения памяти.
	int capacity() {
		return actual_size;
	}

	T& operator [] (int index) {
		if (index<0 || index >= logic_size) {
			std::cout << "\nIndex is out of range" << std::endl;
			exit(1);
		}
		return arr[index]; 
	}

	~my_vector() {
	delete[] arr;
	arr = nullptr;
	}
};

int main() {

	my_vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(6);
	std::cout << " Vector:";
	for (int i{}; i < v.size();++i) {
		std::cout << v.at(i) << " ";
	}
	std::cout << "\n Logic_size: " << v.size();
	std::cout << "\n Actual_size : " << v.capacity();
	std::cout << "\n At(1): " << v.at(1);
	std::cout << "\n v[2]: " << v[2];
	std::cout << "\n v[10]: ";
	std::cout << v[10];
return 0;



}
