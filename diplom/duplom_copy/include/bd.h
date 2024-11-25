#ifndef DATABASE_H
#define DATABASE_H

#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include "except.h"

//*******************************************************************************************
class clientdb {
    std::string db;
public:
    clientdb(std::string db);
    bool checkDatabaseExists(pqxx::connection& conn, const std::string& dbName);
    void createDatabase(pqxx::connection& conn, const std::string& dbName);
    void create_db();
};

//*******************************************************************************************
class manage_db {
    pqxx::connection* conn;
    std::string db;
    void transaction(std::string query);
public:
    manage_db(std::string db);
    pqxx::connection* connect_db();
    void createTable(std::string Word, std::string Document, std::string DocumentWord);
    void addDataTable(std::string Table, std::string value);
    void addWordDocuments(std::string Table, int wordId, int documentId, int frequence);
    //void change_client(std::string name, std::string surname, std::string newname, std::string newsurname, std::string newemail, std::string newphone);
    //void delete_phone(std::string name, std::string surname, std::string phone);
    //void delete_client(std::string name, std::string surname);
    //void out_client(std::string parametr, std::string data);
    //oid select(std::string query, std::string parametr, pqxx::work& txn);
    ~manage_db();
};
//*******************************************************************************************
#endif // DATABASE_H


