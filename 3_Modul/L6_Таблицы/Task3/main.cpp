#include <iostream>
using namespace std;

int simple_string_hash(string word) {
	long long x{};
	for (int i = 0; i < word.size(); ++i) {
		x += static_cast<unsigned char>(word[i]);
	}
	return x;
}

int find(string s, string p) {
	int result{1};
	int h{};
	int size{};
	string p_s{ s, 0, p.size()};
	int p_hash = simple_string_hash(p);

	for (int i = 0; i < s.size() - p.size()+1; ++i) {
		int result{ 1 };
		if (i == 0) {
			h = simple_string_hash(p_s);
		}
		else {
			h -= static_cast<unsigned char>(s[i - 1]);
			h += static_cast<unsigned char>(s[i + p.size()-1]);
		}
		if (h != p_hash) result = -1;
		else {
			for(int j = 0; j < p.size(); ++j){
				if (s[i + j] != p[j]) result = -1;
			}
			if (result == 1) return i;
		}
	}
	return -1;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	string s{}, p{};
	
	cout << "Введите строку, в которой будет осуществляться поиск: ";
	cin >> s;

	do {
	cout << "Введите подстроку, которую нужно найти: ";
	cin >> p;
	if (find(s, p) != -1) {
		cout << "Подстрока " << p << " найдена по индексу " << find(s, p) << "\n";
	}
	else {
		cout << "Подстрока " << p << " не найдена" << "\n";
	}
		if (p.compare("exit") == 0) break;
	} while (true);
}