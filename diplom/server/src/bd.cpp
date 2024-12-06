#include "bd.h"
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