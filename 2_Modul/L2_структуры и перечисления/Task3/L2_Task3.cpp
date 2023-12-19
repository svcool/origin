#include <iostream>

struct address {
	std::string city;
	std::string street;
	int house_number;
	int apartment;
	int index;
	};

void out_address(address a){
std::cout << "Город: " << a.city << std::endl;
std::cout << "Улица: " << a.street << std::endl;
std::cout << "Номер дома: " << a.house_number << std::endl;
std::cout << "Номер квартиры: " << a.apartment << std::endl;
std::cout << "Индекс: " << a.index << std::endl;
std::cout << std::endl;
}


int main() {
	setlocale(LC_ALL, "Russian");
	address n1 = {"Москва", "Арбат", 12, 8, 123456};
	address n2 = { "Ижевск", "Пушкина", 59, 143, 953769};
	out_address(n1);
	out_address(n2);
	return 0;
}