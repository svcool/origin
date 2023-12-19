#include <iostream>
#include <fstream>

class Address {
private:
	std::ifstream f_in;
	std::ofstream f_out;
	int size;
	std::string* arr;
public:
	//void set_address(std::ifstream);//прототип чтения данных из файла
	//void get_output_address_back(std::ofstream); // прототип вывод а адреса в файл в обратном порядке в строки
	//void get_output_address(std::ofstream); // прототип вывод а адреса в файл в строки
	//~Address(); //прототип дескруктора массива
	Address() {}

	/*Address(std::fstream f_in, std::ofstream f_out) {
		this->f_in = f_in;
		this->f_out = f_out;
	}*/

	Address(std::string* arr, int size, std::fstream f_in, std::ofstream f_out) {
		this->arr = arr;
		this->size = size;
	}
	void set_address(std::ifstream& f_in, std::string*& arr, int& size) {
		if (f_in.is_open()) {
			f_in >> size;
			arr = new std::string[size * 4];
			std::string temp{};
			for (int i{}; i < size * 4; i++) {
				f_in >> temp;
				arr[i] = temp;
			}
			f_in.close();

		}
		else std::cout << "Ошибка открытия файла" << std::endl;
	}
	void get_output_address(std::ofstream& f_out, std::string* arr, int size) {
		if (f_out.is_open()) {
			int k{};
			f_out << size << "\n";
			for (int i{}; i < size * 4; i++) {
				f_out << arr[i];
				if ((i + 1) % 4 == 0) f_out << "\n";
				else f_out << ", ";
			}
			f_out.close();
		}
		else std::cout << "Ошибка открытия файла" << std::endl;
	}

	void get_output_address_back(std::ofstream& f_out, std::string* arr, int size) {
		if (f_out.is_open()) {
			int k{}; // для считывания 4 данных адреса
			f_out << size << "\n";
			for (int i{}; i < size; i++) {
				//
				for (int j = (size * 4) - 4 - k; j < (size * 4) - k; j++) {
					f_out << arr[j];
					if (j < (size * 4) - 1 - k) f_out << ", ";
				}
				k += 4; //следующий адрес
				f_out << "\n";
				//std::cout << arr[i];
			}
			f_out.close();
		}
		else std::cout << "Ошибка открытия файла" << std::endl;

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

	~Address() {
		delete[] arr;
	}


};


int main() {
	// локализация
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	// переменные, объекты
	int size{};
	std::ifstream in_file("in.txt");
	std::ofstream f_out("out.txt");
	std::string* arr{};

	Address ad; //экземпляр класса
	ad.set_address(in_file, arr, size); // загружаем данные файла в массив
	ad.sort(arr, size, 1); // сортировка по полю: 1 - город, 2 - улица, 3 - дом, 4 - квартира
	ad.get_output_address(f_out, arr, size); //выводим массив в файл
	return 0;

}