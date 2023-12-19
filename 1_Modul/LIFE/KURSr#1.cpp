#include <iostream>
#include <fstream>
#include <cstdlib>

#ifdef _WIN32
#include "windows.h"
void super_sleep(unsigned int seconds)
{
	Sleep(1000 * seconds);
}
#else
#include <unistd.h>
void super_sleep(unsigned int seconds)
{
	sleep(seconds);
}
#endif

void clear_console()
{
#ifdef _WIN32
	std::system("CLS");
#else
	std::system("clear");
#endif
}

int** create_array(int, int);
void print_array(int**, int, int, int&);
void delete_array(int**, int, int);
void generation(int**, int**, int, int, int&, bool&);
////////////////////////////////////////
int main() {
	int row{}, col{};
	std::ifstream file("in4.txt");
	file >> row;
	file >> col;
	//creating an array
	int** arr = create_array((row + 2), (col + 2));
	int** arrT = create_array((row + 2), (col + 2));
	int cRow{}, cCol{};
	while (!file.eof()) {
		file >> cRow;
		file >> cCol;
		arr[cRow + 1][cCol + 1] = 1;
		// std::cout << arr[cRow][cCol];
	}

	int ac{};
	bool mark{ true };

	for (int i = 1; i > 0 ; i++) {
		ac = 0;
		mark = true;
		if (i == 1) {
			mark = false;
			print_array(arr, row, col, ac);
		}
		else {

			if (!(i % 2 == 0)) {
				generation(arrT, arr, row, col, ac, mark);
			}
			else {
				generation(arr, arrT, row, col, ac, mark);
			}
		}
		std::cout << "Generation: " << i << ". Alive cells: " << ac << std::endl;

		if (mark == true || ac==0) break;
		super_sleep(1);
		clear_console();
	}
	(ac == 0) ? std::cout << "All cells are dead. Game over." :
		std::cout << "The world has stagnated. Game over." << std::endl;



	//dleting the array
	delete_array(arr, (row + 2), (col + 2));
	delete_array(arrT, (row + 2), (col + 2));

	return 0;

}

void generation(int** arr, int** arrT, int row, int col, int& ac, bool& mark) {

	for (int i = 1; i < row + 1; i++) {
		for (int j = 1; j < col + 1; j++) {
			int n{};

			for (int k = i - 1; k <= (i + 1); k++) {
				for (int g = j - 1; g <= (j + 1); g++) {
					//std::cout << k << " " << g << std::endl;
					n += arr[k][g];
				}
			}
			arrT[i][j] = n - arr[i][j]; // вычитаем центральную из расчета

			if (arrT[i][j] == 3 || (arr[i][j] == 1 && arrT[i][j] == 2)) {
				std::cout << "*";
				arrT[i][j] = 1;
				ac++;
			}
			else if (arrT[i][j] < 2 || arrT[i][j] > 3) {
				std::cout << "-";
				arrT[i][j] = 0;

			}
			else {
				std::cout << "-";
				arrT[i][j] = 0;
			}
			if (!(arrT[i][j] == arr[i][j])) mark = false;
		}
		std::cout << std::endl;
	}
}

void delete_array(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
int** create_array(int row, int col) {
	int** arrf = new int* [row];
	for (int i = 0; i < row; i++) {
		arrf[i] = new int[col] {0};
	}
	return arrf;
}
void print_array(int** arr, int row, int col, int& ac) {
	for (int i{ 1 }; i < row + 1; i++) {
		for (int j{ 1 }; j < col + 1; j++) {
			if (arr[i][j] == 1) {
				std::cout << "*";
				ac++;
			}
			else {
				std::cout << "-";
			}
		}
		std::cout << std::endl;
	}
}