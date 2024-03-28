#include <iostream>

using namespace std;

bool prostoNumer(int p) {
	for (int i = 2; i <= sqrt(p); i++)
		if (p % i == 0)
			return false;
	return true;
}

long long real_string_hash(string word, int p, int n) {
	long long x{};
	long long mult{ 1 };
	for (int i = 0; i < word.size(); ++i) {
		x += mult* static_cast<unsigned char>(word[i]);
		mult = mult * p;
	}
	if (x / n == 0) return x;
	return x%n;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	string word{};
	unsigned int p{};
	unsigned int n{};

	do {
		cout << "Введите p: ";
		cin >> p;
		if (!prostoNumer(p)) continue;
		break;
	} while (true);
	
	cout << "Введите n: ";
	cin >> n;

	do {
		cout << "Введите строку: ";
		cin >> word;
		cout << "Хэш строки: " << real_string_hash(word, p, n) << "\n";
		if (word.compare("exit") == 0) break;
	} while (true);
}