#include <iostream>
#include <iomanip>
int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); // ����������� ��������� ������� 
	bool t = true, f = false;
	std::cout << "��������: ||\n";
	std::cout << std::boolalpha
		<< std::setw(7) << t << std::setw(7) << t << std::setw(7) << (t || t) << std::endl
		<< std::setw(7) << f << std::setw(7) << t << std::setw(7) << (f || t) << std::endl
		<< std::setw(7) << t << std::setw(7) << f << std::setw(7) << (t || f) << std::endl
		<< std::setw(7) << f << std::setw(7) << f << std::setw(7) << (f || f) << std::endl;
	std::cout << "\n\n��������: &&\n";
	std::cout << std::boolalpha
		<< std::setw(7) << t << std::setw(7) << t << std::setw(7) << (t && t) << std::endl
		<< std::setw(7) << f << std::setw(7) << t << std::setw(7) << (f && t) << std::endl
		<< std::setw(7) << t << std::setw(7) << f << std::setw(7) << (t && f) << std::endl
		<< std::setw(7) << f << std::setw(7) << f << std::setw(7) << (f && f) << std::endl;
	return 0;
}