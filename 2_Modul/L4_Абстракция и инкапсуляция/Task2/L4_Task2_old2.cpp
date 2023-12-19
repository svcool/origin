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

	Address(std::string city, std::string street, int number_home, int number_apart) {
		this->city = city;
		this->street = street;
		this->number_home = number_home;
		this->number_apart = number_apart;

	}

	std::string get_output_address() {
		address = city + ", " + street + ", " + std::to_string(number_home) + ", " + std::to_string(number_apart);
		return address;
	}

};

void get_output_address_back(std::ofstream& f_out, std::string* arr, int size) {
	if (f_out.is_open()) {
		f_out << size << "\n";
		for (int i{}; i < size; i++) {
			f_out << arr[i] << std::endl;
		}
		f_out.close();
	}
	else std::cout << "Ошибка открытия файла" << std::endl;

}

void set_address(std::ifstream& in_file, std::string*& arr, int& size) {
	arr = new std::string[size * 4];
	std::string temp{};
	for (int i{}; i < size * 4; i++) {
		in_file >> temp;
		arr[i] = temp;
	}
}

// сортировка по полю: 1 - город, 2 - улица, 3 - дом, 4 - квартира
void sort(std::string* arr, int size, int pole) {
	std::string temp{};
	for (int i = pole - 1; i < size * 4; i += 4) {
		for (int j = pole - 1; j < size * 4 - 4; j += 4) {
			if (arr[j] > arr[j + 4]) {
				for (int k = j - pole + 1; k < j - pole + 1 + 4; k++) {
					temp = arr[k];
					arr[k] = arr[k + 4];
					arr[k + 4] = temp;

				}
			}
		}
	}

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
	std::string* arr;
	std::string* arr_sort; //массив для сортировки
	// проверка открытия файла
	if (!in_file.is_open()) { std::cout << "Ошибка открытия файла" << std::endl; return 0; }
	
	in_file >> size;
	arr = new std::string[size];
	//предварительная сортировка
	set_address(in_file, arr_sort, size); // загружаем данные файла в массив
	sort(arr_sort, size, 1); // сортировка по полю: 1 - город, 2 - улица, 3 - дом, 4 - квартира
		
	for (int i{}, k{}; i < size * 4, k <size; i++ ,k++) {
			city = arr_sort[i];
			street = arr_sort[i + 1];
			number_home = std::stoi(arr_sort[i + 2]);
			number_apart = std::stoi(arr_sort[i + 3]);
			i += 3;
			//создаем экземпляр классса и записываем в массив
			Address address(city, street, number_home, number_apart);
			arr[k] = address.get_output_address();
		}
	in_file.close();
	
	get_output_address_back(f_out, arr, size);
	delete[] arr;
	delete[] arr_sort;
	return 0;

}