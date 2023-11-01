#include <iostream>
#include <fstream>

class Addres {
private:
	std::ifstream f_in;
	std::ofstream f_out;
	/*int number_address{};
	std::string city{};
	std::string street{};
	int home{};
	int apartment{};*/
	int size;
	std::string* arr;
public:
	void set_address(std::ifstream&);//прототип чтения данных из файла
	void get_output_address(std::ofstream&); // прототип вывод а адреса в файл
	

	//чтение файла в массив
	/*void set_address(std::ifstream& f_in)  {
		if (f_in.is_open()) {
			f_in >> size;
			std::string* arr = new std::string[size * 4];
			for (int i{}; i < size * 4; i++) {
				f_in >> arr[i];
			}
			f_in.close();
		}
		else std::cout << "Ошибка открытия файла" << std::endl;
	}*/


	//void get_output_address(std::ofstream& f_out) {
	//	if (f_out.is_open()) {
	//		for (int i{}; i < size * 4; i++) {
	//			f_out << arr[i] << " ";
	//		}
	//		f_out.close();
	//	}
	//	else std::cout << "Ошибка открытия файла" << std::endl;

	//}
			
};

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
		for (int i{}; i < size; i++) {
			
			for (int j = (size * 4) - 4 - k; j < (size * 4) - k; j++) {
				f_out << arr[j];
				if(j < (size * 4) - 1 - k) f_out << ", ";
			}
			k += 4;
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
	for (int i = pole - 1; i < size*4; i + 4) {
		for (int j = pole - 1; j < size * 4; j + 4) {
			if (arr[j] > arr[j + 4]) {
				for (int k = j - pole + 1; k < size; k++) {
					temp = arr[k];
					arr[k] = arr[k + 4];
					arr[k + 4] = temp;
				}
			}
		}
	}

}


int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int size;
	std::ifstream in_file("in.txt");
	//in_file >> size;
	std::string* arr{};
	Addres padd;
	set_address(in_file, arr, size);
	for (int i{}; i < size * 4; i++) {
		//f_out << arr[i] << " ";
		//std::cout << arr[0][1] << arr[0][1] << arr[0][2] << arr[0][3] << arr[0][4] << arr[0][5] << arr[0][6] <<"\n";
	}
	if (arr[0] > arr[8]) std::cout << arr[4];
	else std::cout << arr[0];
	std::ofstream f_out("out.txt");
	sort(arr, size, 1);
	get_output_address(f_out, arr, size);

}