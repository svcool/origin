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
    std::vector<SelectResult> selectUrlWord(const std::string& word);
    ~manage_db();
};
//*******************************************************************************************
#endif // DATABASE_H


