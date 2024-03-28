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
	//Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
	int get_element(int index) {
		if (index >= size || index < 0) {
			throw Exsept2();
		}
		return arr[index];
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
		arr.add_element(14);
		//arr.add_element(15);
		//arr.add_element(15);
		std::cout << arr.get_element(3) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}