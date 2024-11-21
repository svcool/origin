#include <globals.h>


using namespace std;
#pragma execution_character_set("utf-8")

int main1()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 10000);
	try {
		//создаем базу данных
		clientdb r("dbwords");
		manage_db db("dbwords");
		//создаем таблицы клиентов и телефонов
db.createTable("Word", "Document", "Document_Word");
		db.addDataTable("Word", "ghbdtn багет");
		db.addDataTable("Document", "слово");
		db.addWordDocuments("Document_Word", 1, 1, 5);
		//db.add_client("Петр", "Петров", "petr@mail.ru", "");
		//db.add_client("Макар", "Макаров", "makar@mail.ru", "111-12345678");
		//db.add_client("Антон", "Антонов", "anton@mail.ru", "1111-12345678");
		////добавление телефона
		//db.add_phone("Иван", "Иванов", "1-112345678");
		//db.add_phone("Макар", "Макаров", "111-112345678");
		////удаление телефона
		//db.delete_phone("Макар", "Макаров", "111-12345678");
		////удаление клиента
		//db.delete_client("Иван", "Иванов");
		////изменение клиента
		//db.change_client("Макар", "Макаров", "Cергей", "Макаров", "sergey@mail.ru", "14353453");
		//// поиск клиентов по параметру
		//db.out_client("surname", "Макаров");
		//db.out_client("phone", "14353453");
		//db.out_client("name", "Петр");
		//db.out_client("email", "petr@mail.ru");
		//db.out_client("email", "pe3333333r@mail.ru");
	}
	//catch (pqxx::sql_error e) {
	catch (const std::exception& e) {
		cout << e.what() << "Исключение" << endl;
	}

	return 0;

}