#include <iostream>
#include <fstream>

int main() {
	int size{};
	std::cout << "Enter array sizt: ";
	std::cin >> size;
	int* arr = new int[size];
	int data{};
	for (int i{} ; i < size ; i++) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> data;
		arr[i] = data;
	}
	std::ofstream f("out.txt");
	f << size << "\n";
	for (int i = (size - 1); i >= 0; i--) {
		f << arr[i] << " ";
	}
	
	delete[] arr;
	f.close();
}