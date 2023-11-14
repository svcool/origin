#include "iostream"
#define MODE 1 // Определили идентификатор MODE
#ifndef MODE
#error Определите константу MODE
#endif

int main(int argc, char** argv) {
setlocale(LC_ALL, "Russian");
#if MODE == 0
	std::cout << "Работаю в режиме тренировки";
#elif MODE == 1
std::cout << "Работаю в боевом режиме" << std::endl;
	int x, y;
	std::cout << "Введите число 1: "; std::cin >> x;
	std::cout << "Введите число 1: "; std::cin >> y;
	std::cout << "Результат сложения: " << (x + y);
#else
	std::cout << "Неизвестный режим. Завершение работы";
#endif
}