#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); // ����������� ��������� �������
	int i {};
	int sum {};
	std::cout << "������� ����� �����: ";
	std::cin >> i;

	while (i != 0) {
		sum += i % 10;
		i = i / 10;
	}
	
	
	std::cout << "����� �����: " << abs(sum) << std::endl;
	return(0);
}