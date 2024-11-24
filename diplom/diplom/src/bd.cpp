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
    std::string query = "INSERT INTO "
        + Table + " VALUES(DEFAULT, '" + value + "');";
    txn.exec(query);
    txn.commit();
    std::cout << "Added a value: " + value + " in Table: " + Table << std::endl;
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
//void manage_db::change_client(std::string name, std::string surname, std::string newname, std::string newsurname, std::string newemail, std::string newphone) {
//    pqxx::work txn1(*conn);
//    std::string query1 = "UPDATE phone "
//        "SET phone = '" + txn1.esc(newphone) + "' "
//        "WHERE clientid = (SELECT id FROM client WHERE name = '" + txn1.esc(name) + "' AND surname = '" + txn1.esc(surname) + "')";
//    txn1.exec(query1);
//    txn1.commit();
//    pqxx::work txn2(*conn);
//    std::string query2 = "UPDATE client "
//        "SET name = '" + txn2.esc(newname) + "', surname = '" + txn2.esc(newsurname) + "', email = '" + txn2.esc(newemail) + "'"
//        "WHERE name = '" + txn2.esc(name) + "' AND surname = '" + txn2.esc(surname) + "'";
//    txn2.exec(query2);
//    txn2.commit();
//    std::cout << "Client data successfully updated!" << std::endl;
//}
////------------------------------------------------------------------------------------------
//void manage_db::delete_phone(std::string name, std::string surname, std::string phone) {
//    pqxx::work txn(*conn);
//    std::string query = "DELETE FROM phone "
//        "WHERE clientid = (SELECT id FROM client WHERE "
//        "name = '" + txn.esc(name) +
//        "' AND surname = '" + txn.esc(surname) +
//        "') AND phone = '" + txn.esc(phone) + "'";
//    txn.exec(query);
//    txn.commit();
//    std::cout << "Topping phone " << phone << " from a client of " << name << ", " << surname << std::endl;
//}
////------------------------------------------------------------------------------------------
//void manage_db::delete_client(std::string name, std::string surname) {
//    pqxx::work txn(*conn);
//    std::string query = "DELETE FROM phone "
//        "WHERE clientid = (SELECT id FROM client WHERE name = '" + txn.esc(name) + "' AND surname = '" + txn.esc(surname) + "');"
//        " DELETE FROM client "
//        "WHERE name = '" + txn.esc(name) + "' AND surname = '" + txn.esc(surname) + "'";
//    txn.exec(query);
//    txn.commit();
//    std::cout << "The client(" << name << " " << surname << ") is deleted!" << std::endl;
//}
////------------------------------------------------------------------------------------------
//void manage_db::out_client(std::string parametr, std::string data) {
//    pqxx::work txn{ *conn };
//    if (parametr == "phone") {
//        std::string query = "SELECT c.name, c.surname FROM client c JOIN phone p ON c.id = p.clientid WHERE p.phone = '" + txn.esc(data) + "'";
//        select(query, parametr, txn);
//    }
//    else if (parametr == "name") {
//        std::string query = "SELECT name, surname FROM client WHERE name = '" + txn.esc(data) + "'";
//        select(query, parametr, txn);
//    }
//    else if (parametr == "surname") {
//        std::string query = "SELECT name, surname FROM client WHERE surname = '" + txn.esc(data) + "'";
//        select(query, parametr, txn);
//    }
//    else if (parametr == "email") {
//        std::string query = "SELECT name, surname FROM client WHERE email = '" + txn.esc(data) + "'";
//        select(query, parametr, txn);
//    }
//    else {
//        throw DbError("Incorrect name of the parameter. The parameter accepts the values: phone, name, surname, email");
//    }
//}
////------------------------------------------------------------------------------------------
//void manage_db::select(std::string query, std::string parametr, pqxx::work& txn) {
//    int check{};
//    auto collection = txn.query<std::string, std::string>(query);
//
//    for (auto elem : collection) {
//        std::cout << "По параметру " << parametr << " найден клиент: " << std::get<0>(elem) << " " << std::get<1>(elem) << ".\n";
//        check++;
//    }
//    if (check == 0) std::cout << "По параметру " << parametr << " клиент не найден." << ".\n";
//}
////------------------------------------------------------------------------------------------
manage_db::~manage_db() {
    conn->close();
    delete conn;
}
//------------------------------------------------------------------------------------------
//*******************************************************************************************