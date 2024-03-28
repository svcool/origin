#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
using namespace std;
#pragma execution_character_set("utf-8")


class db_error : public std::exception {
	std::string message;
public:
	db_error(const std::string& message) : message{ message }
	{}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class clientdb {
	string db;
public:
	clientdb(string db) : db(db) {
		createdb;
	}

	void createdb() {
		// подключение от суперпользователя
		const string cdb = "CREATE DATABASE " + db;
		try {
			pqxx::connection conn(
				"host=localhost "
				"port=5432 "
				"dbname=postgres "
				"user=postgres "
				"password=postgres");

			cout << "База подключена" << endl;

			if (conn.is_open()) {
				pqxx::nontransaction query(conn, "Sample");
				pqxx::result res = query.exec(cdb);
				std::cout << "Database 'clientdb' created successfully!" << std::endl;
			}
			else {
				std::cerr << "Failed to connect to database" << std::endl;
			}
			conn.close();
		}
		catch (const std::exception& err) {
			cout << "Исключение: " << err.what() << endl;
		}
	}
};

class manage_db {
	string name{};
	string surname{};
	string email{};
	string phone{};
	string db;
public:
	manage_db(const string& name, const string& surname, const string& email, const string& phone)
		: name(name), surname(surname), email(email), phone(phone)
	{}
	manage_db(string db) : db(db) {
		createdb;
	}

	void createdb() {
		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=clientdb "
			"user=postgres "
			"password=postgres");
		cout << "База подключена" << endl;
		// Проверка существования базы

		if (c.is_open()) {
			pqxx::work txn(c);
			pqxx::result r = txn.exec("SELECT 1 FROM pg_database WHERE datname = 'clientdb'");
			if (r.empty()) {
				// Базы не существует, создаем ее
				txn.exec("CREATE DATABASE clientdb");
				txn.commit();
				std::cout << "Database " << db << "created successfully!" << std::endl;
			}
			else {
				throw("Database already exists!");
			}
		}

		// Создание таблицы
		void createTable() {
		txn.exec("CREATE TABLE IF NOT EXISTS employee ("
				"id SERIAL PRIMARY KEY,"
				"name VARCHAR(100),"
				"surname,"
				"email,"
				"phone,");
			txn.commit();
			std::cout << "Table 'employee' created successfully!" << std::endl;
		}
		else {
			std::cerr << "Failed to connect to database" << std::endl;
		}

	}
};




		//Метод, создающий структуру БД(таблицы).
		
		

//Метод, позволяющий добавить нового клиента.

//Метод, позволяющий добавить телефон для существующего клиента.

//Метод, позволяющий изменить данные о клиенте.

//Метод, позволяющий удалить телефон у существующего клиента.

//Метод, позволяющий удалить существующего клиента.


	};












int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 10000);
	try {
		pqxx::connection conn(
			"host=localhost "
			"port=5432 "
			"dbname=postgres "
			"user=postgres "
			"password=postgres");
		cout << "База подключена" << endl;

		if (conn.is_open()) {
			pqxx::nontransaction query(conn, "Sample");
			pqxx::result res = query.exec("CREATE DATABASE clientdb;");
			std::cout << "Database 'clientdb' created successfully!" << std::endl;
			}
		else {
			std::cerr << "Failed to connect to database" << std::endl;
		}
		conn.close();

		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=clientdb "
			"user=postgres "
			"password=postgres");
		cout << "База подключена" << endl;
		// Проверка существования базы

		if (c.is_open()) {
			pqxx::work txn(c);
		pqxx::result r = txn.exec("SELECT 1 FROM pg_database WHERE datname = 'clientdb'");
		if (r.empty()) {
			// Базы не существует, создаем ее
			txn.exec("CREATE DATABASE clientdb");
			txn.commit();
			std::cout << "Database 'clientdb' created successfully!" << std::endl;
		}
		else {
			std::cout << "Database 'clientdb' already exists!" << std::endl;
		}

		// Создание таблицы
		txn.exec("CREATE TABLE IF NOT EXISTS employee ("
			"id SERIAL PRIMARY KEY,"
			"name VARCHAR(100),"
			"surname,"
			"email,"
			"phone,");
		txn.commit();
		std::cout << "Table 'employee' created successfully!" << std::endl;
	}
 else {
	 std::cerr << "Failed to connect to database" << std::endl;
		}

		////select
		//pqxx::work tx{ c };
		//for (auto [title, author] : tx.query<std::string, std::string>(
		//	"SELECT title, author FROM book"))
		//{
		//	std::cout << title << " is written by: " << author << ".\n";
		//}

		//pqxx::work tx{ c };
		//std::string author = tx.query_value<std::string>("SELECT author FROM book WHERE id = 3");
		//std::cout << "The author you wanted is: " << author << ".\n";

		////update insert
		//pqxx::work tx{ c };
		//tx.exec("INSERT INTO book(title, author) "
		//	"VALUES('Братья Карамазовы', 'Федор Достоевский')");
		//tx.commit()




	}
	//catch (pqxx::sql_error e) {
	catch (const std::exception& e) {
		cout << e.what() << "Исключение" << endl;
	}

	return 0;

}