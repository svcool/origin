#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); // ����������� ��������� �������
	int i{};
	int sum{};
	std::cout << "������� ����� �����: ";
	std::cin >> i;

	for (int j = 1; j <= 10; j++) {
		std::cout << i << " x " << j << " = " << i* j;
		std::cout << std::endl;
	}
	
	return(0);
}