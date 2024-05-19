#pragma once
#include <string>
#include <iostream>
#include <vector>


// Абстрактный базовый класс
class AbstractQueryBuilder {
protected:
    std::string query;
public:
    virtual AbstractQueryBuilder& AddColumn(const std::string& column) = 0;
    virtual AbstractQueryBuilder& AddFrom(const std::string& table) = 0;
    virtual AbstractQueryBuilder& AddWhere(const std::string& condition, const std::string& value) = 0;
    virtual std::string BuildQuery() = 0;
    ~AbstractQueryBuilder() {};
};

//Строитель запроса SELECT
class SqlSelectQueryBuilder : public AbstractQueryBuilder {
private:
    std::vector<std::string> _column; //для select
    std::string _table; //для from
    std::vector<std::string> _conditions; //для where

public:
    SqlSelectQueryBuilder();

    AbstractQueryBuilder& AddColumn(const std::string& column) override;
    AbstractQueryBuilder& AddFrom(const std::string& table) override;
    AbstractQueryBuilder& AddWhere(const std::string& condition, const std::string& value) override;

    std::string BuildQuery();

};

////Директор
//class SqlQueryDirector {
//public:
//    void ConstructQuery(SqlSelectQueryBuilder& builder) {
//        builder.AddColumn("name").AddColumn("phone").AddFrom("students").AddWhere("id", "42").AddWhere("name", "John");
//    }
//};