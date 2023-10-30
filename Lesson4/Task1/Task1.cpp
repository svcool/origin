#include <iostream>
#include <fstream>
class Address{
private:
	std::ifstream f_in;
	int number_address{};
	std::string city{};
	std::string street{};
	int home{};
	int apartment{};
	int size;
	int* arr = new int[size];
public:
	// Прототипы методов
	Address() {
	
	}
	void set_address(); //прототип чтения данных из файла
	void get_output_address(); // прототип вывод а адреса в файл
	~Address(); // прототип деструктора
	
	void set_address() {
	

	}
	void get_output_address() {
 
	}

	~Address() {
		delete[] arr;
	};
}


int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp1251");
	std::ifstream f_in("in.txt");
	if (f_in.is_open()) {

		f.close();
	
	}
	else std::cout << "Ошибка открытия файла" << std::endl;
	std::ofstream f_out("out.txt");
	f_out <<  
	return 0;
	f.close
}