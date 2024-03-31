#include <iostream>
#include <WT/Dbo/Dbo.h>
#include <WT/Dbo/backend/Postgres.h>
#include <Windows.h>
using namespace std;
#pragma execution_character_set("utf-8")

class user {
public:
	string name = "";
	string phone = "";
	int karma = 0;
	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::field(a, phone, "phone");
		Wt::Dbo::field(a, karma, "karma");
	}


};
//подключается к PostgreSQL;
//создаёт все необходимые таблицы и связи между ними;
//заполняет таблицы тестовыми данными из С++ кода.Данные для заполнения выберите произвольно;
//выводит информацию об издателе(publisher), имя или идентификатор которого принимается через std::cin..
// Программа должна выводить список магазинов, в которых продают книги этого издателя.

int main() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 10000);
	//setlocale(LC_ALL, "Russian");
	try {
		string connectionString =
			"host = localhost "
			"port = 5432 "
			"dbname = postgres "
			"user = postgres "
			"password = postgres";

		unique_ptr<Wt::Dbo::backend::Postgres> connection = make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session s;
		
		
		s.setConnection(move(connection));
		s.mapClass<user>("user");
		Wt::Dbo::Transaction t(s);
		
		
		//s.createTables();



		std::unique_ptr<user> joe(new user);
		joe->name = "Joe";
		joe->phone = "12345";
		joe->karma = 100;
		Wt::Dbo::ptr<user> joeDb = s.add(std::move(joe));
		
		t.commit();
	}
	catch (const exception& err) {
		cout << "Error happened: " << err.what() << endl;
	}



	return 0;
}