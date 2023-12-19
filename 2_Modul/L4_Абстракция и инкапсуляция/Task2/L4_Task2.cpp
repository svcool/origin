#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
	//`<название города > , <название улицы>, <номер дома>, <номер квартиры>`
	std::string city;
	std::string street;
	int number_home;
	int number_apart;
	std::string address;
public:
	Address () {
		city = street = "";
		number_home = number_apart = 0;
	}
	Address(std::string city, std::string street, int number_home, int number_apart) {
		this->city = city;
		this->street = street;
		this->number_home = number_home;
		this->number_apart = number_apart;

	}

	std::string get_city() {
		return city;
	}

	std::string get_street() {
		return street;
	}

	std::string get_number_home() {
		return std::to_string(number_home);
	}
	
	std::string get_number_apart() {
		return std::to_string(number_apart);
	}

	std::string set_print() {
		return get_city() + ", " + get_street() + ", " + get_number_home() + ", " + get_number_apart();
	}

		
};


// сортировка массива
void sort_city(Address* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j].get_city() > arr[j + 1].get_city()) {
				Address temp = arr[j]; // создали дополнительную переменную
				arr[j] = arr[j + 1]; // меняем местами
				arr[j + 1] = temp; // значения элементов
			}
		}
	}
}

// вывод массива
void output_address(std::ofstream& f_out, Address* arr, int size) {
	if (f_out.is_open()) {
		f_out << size << "\n";
		for (int i{}; i < size; i++) {
			f_out << arr[i].set_print() << "\n";
		}
		f_out.close();
	}
	else std::cout << "Ошибка открытия файла" << std::endl;
}

int main() {
	// локализация
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	// переменные, объекты
	int size{};
	std::ifstream in_file("in.txt");
	std::ofstream f_out("out.txt");
	std::string city;
	std::string street;
	int number_home;
	int number_apart;
	// считываем в данные из файла в массив
	Address* arr;
	// проверка открытия файла
	if (!in_file.is_open()) { std::cout << "Ошибка открытия файла" << std::endl; return 0; }

	in_file >> size;
	arr = new Address[size];
	//Заполняем массив объектами класса
	for (int i{}; i < size; i++) {
		in_file >> city;
		in_file >> street;
		in_file >> number_home;
		in_file >> number_apart;
		//создаем экземпляр классса и записываем в массив
		Address address(city, street, number_home, number_apart);
		arr[i] = address;
	}
	in_file.close();

	// сортировка
	sort_city(arr, size);
	//вывод в файл
	output_address(f_out, arr, size);
	
	delete[] arr;
		return 0;
	
}