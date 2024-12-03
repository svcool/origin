#ifndef DATABASE_H
#define DATABASE_H

#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include "except.h"

//*******************************************************************************************
struct DbConfig {
    std::string dbHost;
    int port;
    std::string dbName;
    std::string username;
    std::string password;
};

//*******************************************************************************************
class clientdb {
    std::string db;
    DbConfig dbConfig;
public:
    clientdb(std::string db, DbConfig dbConfig);
    bool checkDatabaseExists(pqxx::connection& conn, const std::string& dbName);
    void createDatabase(pqxx::connection& conn, const std::string& dbName);
    void create_db();
};

struct SelectResult {
    std::string url;
    int frequency;
};

//*******************************************************************************************
class manage_db {
    pqxx::connection* conn;
    std::string db;
    void transaction(std::string query);
    DbConfig dbConfig;
public:
    manage_db(std::string db, DbConfig dbConfig);
    pqxx::connection* connect_db();
    void createTable(std::string Word, std::string Document, std::string DocumentWord);
    void addDataTable(std::string Table, const std::string& column, std::string value);
    void addWordDocuments(std::string Table, int wordId, int documentId, int frequence);
    int select(const std::string& tableName, const std::string& column, const std::string& document);
    std::vector<SelectResult> selectUrlWord(const std::string& word);
    //void change_client(std::string name, std::string surname, std::string newname, std::string newsurname, std::string newemail, std::string newphone);
    //void delete_phone(std::string name, std::string surname, std::string phone);
    //void delete_client(std::string name, std::string surname);
    //void out_client(std::string parametr, std::string data);
    //oid select(std::string query, std::string parametr, pqxx::work& txn);
    ~manage_db();
};
//*******************************************************************************************
#endif // DATABASE_H


