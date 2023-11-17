#include <iostream>
#include <string>

class bad_length : public std::exception
{
public:
	const char* what() const override {
		return "Вы ввели слово запретной длины! До свидания.";
	}
};

int function(std::string str, int forbidden_length) {
	if (str.length() > forbidden_length) throw bad_length();
	return str.length();
}
int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int forbidden_length{};
	std::string word;
	std::cout << "Введите запретную длину: "; std::cin >> forbidden_length;
	try {
		while(true) {
			std::cout << "Введите слово: "; std::cin >> word;
			std::cout << "Длина слова " << word << " равна " << function(word, forbidden_length) << std::endl;
		}
	}
	catch (const bad_length& er) { std::cout << er.what() << std::endl; }
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
	}