#include "bd.h"

//*******************************************************************************************
//------------------------------------------------------------------------------------------
clientdb::clientdb(std::string db, DbConfig dbConfig) : db(db), dbConfig(dbConfig) {
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
        "host=" + dbConfig.dbHost + " "
        "port=" + std::to_string(dbConfig.port) + " "
        "dbname=postgres "
        "user=" + dbConfig.username + " "
        "password=" + dbConfig.password);

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
manage_db::manage_db(std::string db, DbConfig dbConfig) : db(db), dbConfig(dbConfig) {
    connect_db();
}
//------------------------------------------------------------------------------------------
pqxx::connection* manage_db::connect_db() {
    conn = new pqxx::connection(
        "host=" + dbConfig.dbHost + " "
        "port=" + std::to_string(dbConfig.port) + " "
        "dbname=" + db + " "
        "user=" + dbConfig.username + " "
        "password=" + dbConfig.password);

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
void manage_db::addDataTable(std::string Table, const std::string& column, std::string value) {
    pqxx::work txn(*conn);
    std::string query = "INSERT INTO " + txn.esc(Table) + " VALUES(DEFAULT, $1) ON CONFLICT (" + txn.esc(column) + ") DO NOTHING;";

    txn.exec_params(query, value); 
    txn.commit();
    std::cout << "Добавлено значение: " + value + " в таблицу: " + Table << std::endl;
}
//------------------------------------------------------------------------------------------
void manage_db::addWordDocuments(std::string Table, int wordId, int documentId, int frequence) {
    pqxx::work txn(*conn);
    std::string query = "INSERT INTO " + txn.esc(Table) + " VALUES($1, $2, $3) ON CONFLICT (document_id, word_id) DO UPDATE SET frequency = EXCLUDED.frequency;";

    txn.exec_params(query, wordId, documentId, frequence); 
    txn.commit();
    std::cout << "Добавлено значение: " + std::to_string(wordId) + ", " + std::to_string(documentId) + ", " + std::to_string(frequence) + " in Table: " + Table << std::endl;
}
////------------------------------------------------------------------------------------------
// Функция для выполнения запроса и получения результата
int manage_db::select(const std::string& tableName, const std::string& column, const std::string& value) {
    pqxx::work txn{ *conn };
    int id = -1;

    try {
        std::string query = "SELECT " + txn.esc(tableName) + "_id FROM " + txn.esc(tableName) + " WHERE " + txn.esc(column) + " = $1;";
        pqxx::result collection = txn.exec_params(query, value); // Выполняем запрос с параметром

        if (!collection.empty()) {
            id = collection[0][0].as<int>(); // Получаем ID из первого результата
            std::cout << "По параметру " << value << " найден ID: " << id << ".\n";
        }
        else {
            std::cout << "Запись не найдена для параметра: " << value << ".\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при выполнении запроса: " << e.what() << std::endl;
    }
    return id;
}
//------------------------------------------------------------------------------------------
std::vector<SelectResult> manage_db::selectUrlWord(const std::string& word) {
    pqxx::work txn{*conn};
    const std::string query = R"(
        SELECT d.title, w.name, dw.frequency
        FROM document_word dw
        JOIN document d ON dw.document_id = d.document_id 
        JOIN word w ON dw.word_id = w.word_id 
        WHERE w.name = $1
        ORDER BY dw.frequency DESC;
        )";

    pqxx::result collection = txn.exec_params(query, word);

std::vector<SelectResult> urlFrequency;// Карта для хранения частоты слов

for (const auto& row : collection) {
    urlFrequency.push_back({ row[0].as<std::string>(), row[2].as<int>() });
}

//for (const auto& row : urlFrequency) {
//    std::cout << row.url << "--" << row.frequency << std::endl;
//}

txn.commit();

return urlFrequency; // Возвращаем вектор с результатами
}

////------------------------------------------------------------------------------------------
manage_db::~manage_db() {
    conn->close();
    delete conn;
}
//------------------------------------------------------------------------------------------
//*******************************************************************************************