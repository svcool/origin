#include <iostream> 
#include <fstream>
#include <cstdlib>
void slep_console(int time) {
#ifdef _WIN32
#include <windows.h>
	Sleep(1000 * time);
#else
#include <unistd.h>
	sleep(time);
#endif
}
void clear_console() {
#ifdef _WIN32
	std::system("CLS");
#else
	std::system("clear");
#endif
}
/////////////////////////////
void generation(int**, int**, int, int, bool&, int&);
/////////////////////////////
int main() {
	int row{}, col{}, cRow{}, cCol{}, ac{}; // row,col -  ������ �������, �Row, cCol - ���������� ����� ������, �� - ���������� ����� ������
	bool mark{ true }; // ������ ��� ���������� ����� �������
	std::ifstream file("in.txt");
	if (!file.is_open()) {
		std::cout << "File not found" << std::endl;
		return 0;
	}
	file >> row >> col; // ������ �� ����� ������ �������
	int** arr = new int* [row + 2], ** arrT = new int* [row + 2]; //������� ������� arr � arrTemp c ������� �� �����
	for (int i = 0; i < row + 2; i++) {
		arr[i] = new int[col + 2] {0};
		arrT[i] = new int[col + 2] {0};
	}
	while (!file.eof()) {
		file >> cRow >> cCol;
		arr[cRow + 1][cCol + 1] = 1; //��������� ��������� ������
	}
	for (int i = 1; i > 0; i++) {
		ac = 0;
		mark = true;
		if (i == 1) {
			generation(arr, arr, row, col, mark, ac); //������ ��������� �� �����
		}
		else
		{
			if (!(i % 2 == 0)) generation(arrT, arr, row, col, mark, ac);
			else generation(arr, arrT, row, col, mark, ac);
		}
		std::cout << "Generation: " << i << ". Alive cells: " << ac << std::endl;
		if (mark == true || ac == 0) break; // ����� �� ����� ���� ����� ������ �� ��� ���������� ��������� ��������� � ���������
		slep_console(1);
		clear_console();
	}
	(ac == 0) ? std::cout << "All cells are dead. Game over." : std::cout << "The world has stagnated. Game over." << std::endl;
	//�������� ��������
	for (int i = 0; i < row + 2; i++) {
		delete[] arr[i];
		delete[] arrT[i];
	}
	delete[] arr;
	delete[] arrT;
	file.close(); // ��������� ����
	return 0;
}
///////////////////////////////////////////////////////
void generation(int** arr, int** arrT, int row, int col, bool& mark, int& ac) {
	for (int i{ 1 }; i < row + 1; i++) {
		for (int j{ 1 }; j < col + 1; j++) {
			if (arr == arrT) {
				mark = false; //����� ���� �� ��������� ����� ������� ����� ������
				if (arr[i][j] == 1) {
					std::cout << "*";
					ac++;
				}
				else std::cout << "-";
			}
			else {
				int n{};
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int g = j - 1; g <= j + 1; g++) n += arr[k][g]; // ������� ����� �������
				}
				arrT[i][j] = n - arr[i][j]; // �������� ����������� �� �������
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
		}
		std::cout << std::endl;
	}
}