#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include <pugixml.hpp> 

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
// создание базы
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
				throw("Failed to connect to database");
			}
			conn.close();
	}
};
//управление базой
class manage_db {
	pqxx::connection* conn;

	void transaction(string query) {
		pqxx::work txn(*conn);
		txn.exec(query);
		txn.commit();
	}
public:
	manage_db() {
		connect_db();
	}

	pqxx::connection* connect_db() {
		// подключение от суперпользователя
	  		conn = new pqxx::connection("host=localhost "
				"port=5432 "
				"dbname=clientdb "
				"user=postgres "
				"password=postgres");

			if (conn->is_open()) {
				std::cout << "Opened database successfully: " << conn->dbname() << std::endl;
			}
			else {
				throw ("Failed to open database");
			}
	
		return conn;
	}

	// Метод, создающий структуру БД(таблицы).
	void createTable(string client, string phone) {
			string query1 = "CREATE TABLE IF NOT EXISTS " + client + " ("
				"id SERIAL PRIMARY KEY, "
				"name VARCHAR(100) NOT NULL, "
				"surname VARCHAR(100) NOT NULL, "
				"email VARCHAR(100) UNIQUE"
				")";
			transaction(query1);
			string query2 = "CREATE TABLE IF NOT EXISTS " + phone + " ("
				"id SERIAL PRIMARY KEY, "
				"phone VARCHAR(30), "
				"clientid INTEGER REFERENCES " + client + 
				"(id) ON DELETE CASCADE"
				")";
			transaction(query2);
		std::cout << "Table " + client + ", " + phone + " created successfully!" << std::endl;
	}

	//Метод, позволяющий добавить клиента
	void add_client(string name, string surname, string email) {
		add_client(name, surname, email, "");
	}

	void add_client(string name, string surname, string email, string phone) {
		pqxx::work txn(*conn);
		string query = "WITH new_client AS("
			"INSERT INTO client(name, surname, email) "
			"VALUES('" + txn.esc(name) + "', '" + txn.esc(surname) + "', '" + txn.esc(email) + "') ON CONFLICT DO NOTHING RETURNING id"
			") "
			"INSERT INTO phone(phone, clientid) "
			"VALUES('" + txn.esc(phone) + "', (SELECT id FROM new_client)) "
			"ON CONFLICT DO NOTHING";
		txn.exec(query);
		txn.commit();
		std::cout << "Added a client: " << name << ", " << surname << ", " << email << ", " << phone << std::endl;
	}

//Метод, позволяющий добавить телефон для существующего клиента.
	void add_phone(string name, string surname, string phone) {
		pqxx::work txn(*conn);
		string query = "INSERT INTO phone(phone, clientid) "
			"VALUES('" + txn.esc(phone) + "',"
			"(SELECT id FROM client WHERE name = '" + txn.esc(name) + "' AND surname = '" + txn.esc(surname) + "')"
			")";
		txn.exec(query);
		txn.commit();
		std::cout << "The phone is added! " + phone << std::endl;
	}

//Метод, позволяющий изменить данные о клиенте.
	void change_client(string name, string surname, string newname, string newsurname, string newemail, string newphone) {
		pqxx::work txn1(*conn);
		string query1 = "UPDATE phone "
			"SET phone = '" + txn1.esc(newphone) + "' "
			"WHERE clientid = (SELECT id FROM client WHERE name = '" + txn1.esc(name) + "' AND surname = '" + txn1.esc(surname) + "')";
		txn1.exec(query1);
		txn1.commit();
		pqxx::work txn2(*conn);
		string query2 = "UPDATE client "
			"SET name = '" + txn2.esc(newname) + "', surname = '" + txn2.esc(newsurname) + "', email = '" + txn2.esc(newemail) + "'"
			"WHERE name = '" + txn2.esc(name) + "' AND surname = '" + txn2.esc(surname) +"'";
		txn2.exec(query2);
		txn2.commit();
		std::cout << "Client data successfully updated!" << std::endl;
	}

//Метод, позволяющий удалить телефон у существующего клиента.
	void delete_phone(string name, string surname, string phone) {
		pqxx::work txn(*conn);
		string query = "DELETE FROM phone "
			"WHERE clientid = (SELECT id FROM client WHERE "
			"name = '" + txn.esc(name) +
			"' AND surname = '" + txn.esc(surname) +
			"') AND phone = '" + txn.esc(phone) + "'";
		txn.exec(query);
		txn.commit();
		std::cout << "Topping phone " << phone << " from a client of " << name << ", " << surname << std::endl;
	}

//Метод, позволяющий удалить существующего клиента.
	void delete_client(string name, string surname) {
		pqxx::work txn(*conn);
		string query = "DELETE FROM phone "
			"WHERE clientid = (SELECT id FROM client WHERE name = '" + txn.esc(name) + "' AND surname = '" + txn.esc(surname) + "');"
			" DELETE FROM client "
			"WHERE name = '" + txn.esc(name) + "' AND surname = '" + txn.esc(surname) + "'";
		txn.exec(query);
		txn.commit();
		std::cout << "The client(" << name << " " << surname << ") is deleted!" << std::endl;
	}

	// Метод, позволяющий найти клиента по его данным — имени, фамилии, email или телефону.
	void out_client(string parametr, string data) {
		pqxx::work txn{ *conn };
		if (parametr == "phone") {
			string query = "SELECT c.name, c.surname FROM client c JOIN phone p ON c.id = p.clientid WHERE p.phone = '" + txn.esc(data) + "'";
			select(query, parametr, txn);
			}
		else if (parametr == "name") {
			string query = "SELECT name, surname FROM client WHERE name = '" + txn.esc(data) + "'";
			select(query, parametr, txn);
		}
		else if (parametr == "surname") {
			string query = "SELECT name, surname FROM client WHERE surname = '" + txn.esc(data) + "'";
			select(query, parametr, txn);
		}
		else if (parametr == "email") {
			string query = "SELECT name, surname FROM client WHERE email = '" + txn.esc(data) + "'";
			select(query, parametr, txn);
		}
		else {
			throw ("Incorrect name of the parameter. The parameter accepts the values: phone, name , surname, email");
		}
	
	}

	void select(string query, string parametr, pqxx::work& txn) {
		int check{};
		auto collection = txn.query<std::string, std::string>(query);
		
		for (auto elem : collection)
		{
			std::cout << "По параметру " << parametr << " найден клиент: " << get<0>(elem) << " " << get<1>(elem) << ".\n";
			check++;
		}
	if(check == 0) std::cout << "По параметру " << parametr << " клиент не найден." << ".\n";
	}

	~manage_db() {
		conn->close();
		delete conn;
	}

};


int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 10000);
	try {
		//создаем базу данных
		clientdb r("clientdb");
		manage_db db;
		//создаем таблицы клиентов и телефонов
		db.createTable("client", "phone");
		db.add_client("Иван", "Иванов", "ivan@mail.ru", "1-12345678");
		db.add_client("Петр", "Петров", "petr@mail.ru", "");
		db.add_client("Макар", "Макаров", "makar@mail.ru", "111-12345678");
		db.add_client("Антон", "Антонов", "anton@mail.ru", "1111-12345678");
		//добавление телефона
		db.add_phone("Иван", "Иванов", "1-112345678");
		db.add_phone("Макар", "Макаров", "111-112345678");
		//удаление телефона
		db.delete_phone("Макар", "Макаров", "111-12345678");
		//удаление клиента
		db.delete_client("Иван", "Иванов");
		//изменение клиента
		db.change_client("Макар", "Макаров", "Cергей", "Макаров", "sergey@mail.ru", "14353453");
		// поиск клиентов по параметру
		db.out_client("surname", "Макаров");
		db.out_client("phone", "14353453");
		db.out_client("name", "Петр");
		db.out_client("email", "petr@mail.ru");
		db.out_client("email", "pe3333333r@mail.ru");
	}
	//catch (pqxx::sql_error e) {
	catch (const std::exception& e) {
		cout << e.what() << "Исключение" << endl;
	}

	return 0;

}