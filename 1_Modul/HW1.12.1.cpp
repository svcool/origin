#include <iostream>
#include <fstream>
//#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	//system("chcp 1251");
	std::string s;
	std::ifstream f("in.txt"); // ������� ����
	if (f.is_open()) {
		while (!(f >> s).eof()) {
			std::cout << s << std::endl;
		}
		f.close(); //������� ����
	}
	else {
		std::cout << "The file could not be opened" << std::endl;
	}

	return 0;
}