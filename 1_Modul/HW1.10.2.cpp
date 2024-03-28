#include <iostream>
//#include <cstdlib> для calloc, malloc

void output_arr(double*, int);
void delete_arr(double*);
double* create_arr(int);
int main() {
	int size{};
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	double* arr = create_arr(size);
	output_arr(arr, size);
	delete_arr(arr);
	return 0;
}

double* create_arr(int size) {
	void* ptr = malloc(size * sizeof(double));
	//void* ptr = calloc(size, sizeof(double));
	//ptr = 0;
	memset(ptr, '\0', size * sizeof(double)); // очистка памяти memset
	double* ptrarr = static_cast<double*>(ptr);
	// очистка циклом
	/*for (int i = 0; i < size; i++) { 
		ptrarr[i] = 0;
	}*/
	return ptrarr;
	//return new double[size] {};
}

void output_arr(double* arr, int s) {
	for (int i = 0; i < s; i++) {
		if (i == 0) { std::cout << "Array: " << arr[i]; }
		else { std::cout << " " << arr[i]; }
	}
	std::cout << std::endl;
}

void delete_arr(double* arr) {
	//delete[] arr;
	free(arr);
}