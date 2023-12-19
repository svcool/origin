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

		void get_output_address_back(std::ofstream & f_out, std::string * arr, int size) {
			if (f_out.is_open()) {
				f_out << size << "\n";
				for (int i = size - 1; i >= 0; i--) {
					f_out << arr[i] << std::endl;
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
	std::string* arr;
	// проверка открытия файла
	if (!in_file.is_open()) { std::cout << "Ошибка открытия файла" << std::endl; return 0; }
		
	in_file >> size;
	arr = new std::string[size];
		
	for (int i{}; i < size; i++) {
			in_file >> city;
			in_file >> street;
			in_file >> number_home;
			in_file >> number_apart;
			//создаем экземпляр классса и записываем в массив
			Address address(city, street, number_home, number_apart);
			arr[i] = address.get_output_address();
		}
		in_file.close();


	get_output_address_back(f_out, arr,size);
	delete[] arr;
	return 0;

}