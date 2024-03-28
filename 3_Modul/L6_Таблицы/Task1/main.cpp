#include <iostream>
using namespace std;

int simple_string_hash(string word) {
	int x{};
	for (int i = 0; i < word.size(); ++i) {
		 x +=  static_cast<unsigned char>(word[i]);
	}
	return x;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	string word{};

	do {
		cout << "Введите строку: ";
		cin >> word;
		cout << "Наивный хэш строки " << word << " = " << simple_string_hash(word) << "\n";
		if (word.compare("exit") == 0) break;
	} while (true);
}