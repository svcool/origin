#include <iostream>

struct Exsept1 : std::exception {
	const char* what() const noexcept
	{
		return "Нет места для нового элемента, увеличьте размер массива";
	}
};
struct Exsept2 : std::exception {
	const char* what() const noexcept
	{
		return "Индекс не корректен";
	}
};

class smart_array {
	int size{};
	int* arr;
	int count{};
public:
	smart_array(int size) :size(size) {
		arr = new int[size] {NULL};
		std::cout << "Вызван конструктор\n";
	}
	//Функция добавления нового элемента в массив. Не забудьте обработать случай, когда количество элементов больше количества элементов, на которую выделена память.
	void add_element(int x) {
		if (count == size) {
			throw Exsept1();
		}
		if (arr[count] == NULL) {
			arr[count] = x;
		}

		++count;
	}
	int get_size() {
		return size;
	}
	//Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
	int get_element(int index) {
		if (index >= size || index < 0) {
			throw Exsept2();
		}
		return arr[index];
	}

	smart_array& operator=(smart_array& arr2) {
		if (&arr2 != this) {
			delete[] arr;
			int* newarr = new int[arr2.size];
			for (int i{}; i < arr2.size; i++) {
				newarr[i] = arr2.get_element(i);
			}
			this->arr = newarr;// присваиваем указателю текущего объекта новый указатель
			size = arr2.size; // изменяем размер массива
			count = arr2.count; //копируем количество добавленных элементов
		}
		return *this; 
	}
	//Деструктор.
	~smart_array() {
		delete[] arr;
		std::cout << "Вызван деструктор\n";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(3);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

		arr.add_element(155);
	
		for (int i = 0; i < arr.get_size(); i++) {
			std::cout << arr.get_element(i) << " ";
		}
		std::cout << "\n";
		for (int i = 0; i < new_array.get_size(); i++) {
			std::cout << new_array.get_element(i) << " ";
		}
		std::cout << "\n";

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}