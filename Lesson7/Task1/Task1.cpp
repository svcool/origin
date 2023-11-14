#include "iostream"

#include "func.h"
#define MODE 1 // Определили идентификатор MODE
#ifndef MODE
#error Определите константу MODE
#endif

int main(int argc, char** argv) {
setlocale(LC_ALL, "Russian");
#if MODE == 0
	std::cout << "Работаю в режиме тренировки";
#elif MODE == 1
std::cout << "Работаею в боевом режиме" << std::endl;
add();
#else
	std::cout << "Неизвестный режим. Завершение работы";
#endif
}
