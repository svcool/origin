#include <iostream>
#include <fstream>

int main() {
	std::ifstream f("in3.txt");
	//�������� �������� �����
	if (f.is_open()) {
		int col{}, row{};
		f >> row;
		f >> col;
		// ������� ���. ������
		int** arr = new int* [row];
		for (int i{}; i < row; i++) {
			arr[i] = new int[col];
		}
		//������ ���� � ������
		for (int i{}; i < row; i++) {
			for (int j{}; j < col; j++) {
				f >> arr[i][j];
			}
		}
		//������� �� ������� � �������� �������
		for (int i{}; i < row; i++) {
			for (int j = (col - 1); j >= 0; j--) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << std::endl;
		}

		//������� ������ �� ������
			for (int i{}; i < row; i++) {
				delete[] arr[i];
		}
			delete[] arr;
		//������� ����
			f.close(); 
	}

	else std::cout << "Fail to open file!" << std::endl;


		return 0;
	}