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
		create_db();
	}

	bool checkDatabaseExists(pqxx::connection& conn, const std::string& dbName) {
		pqxx::work txn(conn);
		pqxx::result result = txn.exec("SELECT 1 FROM pg_database WHERE datname = " + txn.quote(dbName));
		txn.commit();
		return !result.empty();
	}

	void createDatabase(pqxx::connection& conn, const std::string& dbName) {
		pqxx::nontransaction query(conn, "Sample");
		pqxx::result res = query.exec("CREATE DATABASE " + dbName);
		std::cout << "Database '" << dbName << "' created successfully!" << std::endl;
	}

	void create_db() {
		// подключение от суперпользователя
		
			pqxx::connection conn(
				"host=localhost "
				"port=5432 "
				"dbname=postgres "
				"user=postgres "
				"password=postgres");

			cout << "База подключена" << endl;

			// Проверка существования базы
			if (conn.is_open()) {
				string dbName = db;

				if (!checkDatabaseExists(conn, dbName)) {
					createDatabase(conn, dbName);
				}
				else {
					std::cout << "Database '" << dbName << "' already exists!" << std::endl;
				}
			}
			else {
				std::cerr << "Failed to connect to database" << std::endl;
			}
			conn.close();
	}
};

class manage_db {
	//string name{};
	//string surname{};
	//string email{};
	//string phone{};
	string dbname;
	string user;
	string password;
	
public:
	pqxx::connection conn{};
	//manage_db(const string& name, const string& surname, const string& email, const string& phone)
	//	: name(name), surname(surname), email(email), phone(phone)
	//{}
	manage_db() {
		conn = connect_db();
	}


	pqxx::connection& connect_db() {
		// подключение от суперпользователя
		conn = pqxx::connection("host=localhost "
				"port=5432 "
				"dbname=postgres "
				"user=postgres "
			"password=postgres");
			

		if (conn.is_open()) {
			std::cout << "Opened database successfully: " << conn.dbname() << std::endl;
		}
		else {
			std::cerr << "Failed to open database" << std::endl;
		}
		return conn;
	}

	// //Метод, создающий структуру БД(таблицы).
	/*void createTable() {
		pqxx::work txn(conn);
		txn.exec("CREATE TABLE IF NOT EXISTS phone ("
			"id SERIAL PRIMARY KEY,"
			"text VARCHAR(30),");
			txn.commit();
		std::cout << "Table 'employee' created successfully!" << std::endl;

		txn.exec("CREATE TABLE IF NOT EXISTS employee ("
			"id SERIAL PRIMARY KEY,"
			"name VARCHAR(100),"
			"surname VARCHAR(100),"
			"email VARCHAR(100) UNIQUE,"
			"phoneId INTEGER REFERENCES phone(id),");
		txn.commit();
		std::cout << "Table 'employee' created successfully!" << std::endl;


	}*/

//Метод, позволяющий добавить телефон для существующего клиента.

//Метод, позволяющий изменить данные о клиенте.

//Метод, позволяющий удалить телефон у существующего клиента.

//Метод, позволяющий удалить существующего клиента.






};


		
		

//Метод, позволяющий добавить нового клиента.

int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 10000);
	try {
const std::string dbname = "cliendb";
		const std::string user = "postgres";
		const std::string password = "postgres";

		clientdb r("clientdb");


		
		manage_db db;

		


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