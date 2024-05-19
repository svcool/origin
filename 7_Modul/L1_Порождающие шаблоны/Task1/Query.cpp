#include "exception.h"
#include "Query.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {}

AbstractQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) {
    _column.push_back(column);
    return *this;
}
AbstractQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) {
    _table = table;
    return *this;
}
AbstractQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& condition, const std::string& value) {
    _conditions.push_back(condition + "=" + value);
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
    //"SELECT name, phone FROM students WHERE id='42' AND name='John';"
    query = "SELECT";
    if (_column.empty()) {
        throw QueryException("Запрос не может быть сконструирован, не выбраны колонки");
    }
    for (std::string n : _column) {
        query += " " + n + ",";
    }
    query.pop_back();
    query += " ";
    //FROM
    query += "FROM";
    if (_table.empty()) throw QueryException("Запрос не может быть сконструирован, не выбрана таблица");
    query += " " + _table + " ";
    //WHERE
    query += "WHERE";
    for (int i = 0; i < _conditions.size(); i++) {
        query += " " + _conditions[i];
        if (i < _conditions.size() - 1) {
            query += " AND";
        }
    }
    query += ";";
    return query;
}

