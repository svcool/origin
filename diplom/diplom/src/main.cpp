#include <globals.h>
#include <cstdlib> // Для system()

using namespace std;
#pragma execution_character_set("utf-8")

int main1()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 10000);
	try {
		
	}
	//catch (pqxx::sql_error e) {
	catch (const std::exception& e) {
		cout << e.what() << "Исключение" << endl;
	}


	//парсе ini - создание объекта
	//парсер start - вызов работы парсера
	//получение из парсера данных database
	// создание БД
	// 
	// получение данных спайдера порт и стартовая страница, получение новых ссылок чрез Xpath.
	// запуск спайдера:
	//   -Скачиваем страницу и собираем ссылки
	//   -Создаем очередь из ссылок, мнгопоточно производим скачивание через hhtpclient  и индексация
	//	- Задается глубина рекурсии
	//
	// 
	// получение данных краулера(поисковика)
	//старт сервера html(анализ частоты вводимого слова из БД)
	// 
	// ***************************************************************************************
	//открытие страницы в веб браузере
	std::string url = "http://localhost:8080/search"; // Укажите URL вашей страницы поиска
	// Открываем страницу в браузере
#ifdef _WIN32
	// Для Windows
	system(("start " + url).c_str());
#elif __APPLE__
	// Для macOS
	system(("open " + url).c_str());
#else
	// Для Linux
	system(("xdg-open " + url).c_str());
#endif
	std::cout << "Страница поиска открыта в браузере." << std::endl;
	return 0;

}