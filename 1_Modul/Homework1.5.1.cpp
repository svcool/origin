#include <iostream>

int main()
{
	//setlocale(LC_ALL, "Russian");
	//system("chcp 1251"); // ����������� ��������� �������
	int arr[10];
	int i{ 0 };
	// std::size(arr) �� �������� � ripl - ���������� ������ �������
	int sizearr = sizeof(arr) / sizeof(arr[0]);
	//��������� ������
	for (int i{}; i < sizearr; i++) {
		arr[i] = i * 2 + 4;
	}


	//������� ������
	for (int i{}; i < sizearr; i++) {
		std::cout << arr[i];
		(i == sizearr - 1) ? (std::cout << " ") : (std::cout << ", ");
	}
	std::cout << std::endl;
	return(0);
}