#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>

// ����������� ������� �����
class AbstractQueryBuilder {
protected:
    std::string query;
public:
    virtual AbstractQueryBuilder& AddColumn(const std::vector<std::string>& columns) noexcept = 0;
    virtual AbstractQueryBuilder& AddFrom(const std::string& table) noexcept = 0;
    virtual AbstractQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept = 0;
    virtual std::string BuildQuery() = 0;
    ~AbstractQueryBuilder() {};
};

//��������� ������� SELECT
class SqlSelectQueryBuilder : public AbstractQueryBuilder {
private:
    std::vector<std::string> _column; //��� select
    std::string _table; //��� from
    std::map<std::string, std::string> _conditions; //��� where
public:
    SqlSelectQueryBuilder();

    AbstractQueryBuilder& AddColumn(const std::vector<std::string>& columns) noexcept override;
    AbstractQueryBuilder& AddFrom(const std::string& table) noexcept override;
    AbstractQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept override;
    std::string BuildQuery();

};

////��������
//class SqlQueryDirector {
//public:
//    void ConstructQuery(SqlSelectQueryBuilder& builder) {
//        builder.AddColumn("name").AddColumn("phone").AddFrom("students").AddWhere("id", "42").AddWhere("name", "John");
//    }
//};