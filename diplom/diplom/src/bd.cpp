#include "bd.h"

//*******************************************************************************************
//------------------------------------------------------------------------------------------
clientdb::clientdb(std::string db) : db(db) {
    create_db();
}
//------------------------------------------------------------------------------------------
bool clientdb::checkDatabaseExists(pqxx::connection& conn, const std::string& dbName) {
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT 1 FROM pg_database WHERE datname = " + txn.quote(dbName));
    txn.commit();
    return !result.empty();
}
//------------------------------------------------------------------------------------------
void clientdb::createDatabase(pqxx::connection& conn, const std::string& dbName) {
    pqxx::nontransaction query(conn, "Sample");
    query.exec("CREATE DATABASE " + dbName);
    std::cout << "Database '" << dbName << "' created successfully!" << std::endl;
}
//------------------------------------------------------------------------------------------
void clientdb::create_db() {
    pqxx::connection conn(
        "host=localhost "
        "port=5432 "
        "dbname=postgres "
        "user=postgres "
        "password=postgres");

    std::cout << "База подключена" << std::endl;

    if (conn.is_open()) {
        std::string dbName = db;

        if (!checkDatabaseExists(conn, dbName)) {
            createDatabase(conn, dbName);
        }
        else {
            std::cout << "Database '" << dbName << "' already exists!" << std::endl;
        }
    }
    else {
        throw DbError("Failed to connect to database");
    }
    conn.close();
}
//------------------------------------------------------------------------------------------
//*******************************************************************************************
//------------------------------------------------------------------------------------------
manage_db::manage_db(std::string db) : db(db) {
    connect_db();
}
//------------------------------------------------------------------------------------------
pqxx::connection* manage_db::connect_db() {
    conn = new pqxx::connection("host=localhost "
        "port=5432 "
        "dbname=" + db + " "
        "user=postgres "
        "password=postgres");

    if (conn->is_open()) {
        std::cout << "Opened database successfully: " << conn->dbname() << std::endl;
    }
    else {
        throw DbError("Failed to open database");
    }

    return conn;
}
//------------------------------------------------------------------------------------------
void manage_db::transaction(std::string query) {
    pqxx::work txn(*conn);
    txn.exec(query);
    txn.commit();
}
//------------------------------------------------------------------------------------------
void manage_db::createTable(std::string Word, std::string Document, std::string DocumentWord) {
    
    std::string query1 = "CREATE TABLE IF NOT EXISTS " + Word + " ("
        + Word + "_id SERIAL PRIMARY KEY, "
        "name VARCHAR(100) NOT NULL UNIQUE"
        ")";
    transaction(query1);

    std::string query2 = "CREATE TABLE IF NOT EXISTS " + Document + " ("
        + Document + "_id SERIAL PRIMARY KEY, "
        "title VARCHAR(255) NOT NULL UNIQUE"
        ")";
    transaction(query2);

       std::string query3 = "CREATE TABLE IF NOT EXISTS " + DocumentWord + " ("
        + Document+"_id INTEGER REFERENCES " + Document + "(" + Document + "_id" + "), "
        + Word + "_id INTEGER REFERENCES " + Word + "(" + Word + "_id" + "), "
        "frequency INTEGER NOT NULL, "
        "CONSTRAINT pk_document_word primary key(" + Document + "_id," + Word + "_id)"
        ")";
    transaction(query3); 

    std::cout << "Table " + Document + ", " + Word + ", " + DocumentWord + " created successfully!" << std::endl;
}
//------------------------------------------------------------------------------------------
void manage_db::addDataTable(std::string Table, std::string value) {
    pqxx::work txn(*conn);
    std::string query = "INSERT INTO " + Table + " VALUES(DEFAULT, '" + txn.esc(value) + "');";

    try {
        txn.exec(query);
        txn.commit();
        std::cout << "Добавлено значение: " + value + " в таблицу: " + Table << std::endl;
    }
    catch (const std::exception& e) {
        DatabaseExceptionHandler handler(txn);
        handler.handle(e); // Обрабатываем исключение
    }
}
//------------------------------------------------------------------------------------------
void manage_db::addWordDocuments(std::string Table, int wordId, int documentId, int frequence) {
    pqxx::work txn(*conn);
    std::string query = "INSERT INTO "
        + Table + " VALUES(" + std::to_string(wordId) + ", " + std::to_string(documentId) + ", " +  std::to_string(frequence) + "); ";
    txn.exec(query);
    txn.commit();
    std::cout << "Added a frequence: " + std::to_string(frequence) + " in Table: " + Table << std::endl;
}
////------------------------------------------------------------------------------------------
// Функция для выполнения запроса и получения результата
    int manage_db::select(const std::string& tableName, const std::string& document, const std::string& column) {
        pqxx::work txn{ *conn };
        int id = -1; // Идентификатор по умолчанию

        try {
            // Формируем запрос с использованием безопасного экранирования
            std::string query = "SELECT "+ tableName + "_id" + " FROM " + tableName + " WHERE " + column + " = '" + txn.esc(document) + "'; ";
            pqxx::result collection = txn.exec(query); // Выполняем запрос

            // Проверяем, есть ли результаты
            if (!collection.empty()) {
                id = collection[0][0].as<int>(); // Получаем ID из первого результата
                std::cout << "По параметру " << document << " найден ID: " << id << ".\n";
            } else {
                std::cout << "Запись не найдена для параметра: " << document << ".\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Ошибка при выполнении запроса: " << e.what() << std::endl;
        }

        return id; // Возвращаем найденный ID или -1, если не найден
    }
////------------------------------------------------------------------------------------------
manage_db::~manage_db() {
    conn->close();
    delete conn;
}
//------------------------------------------------------------------------------------------
//*******************************************************************************************