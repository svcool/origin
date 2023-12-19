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
#include "func.h"
add();
#else
	std::cout << "Неизвестный режим. Завершение работы";
#endif
}