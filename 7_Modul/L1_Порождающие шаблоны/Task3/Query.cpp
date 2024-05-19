#include "exception.h"
#include "Query.h"

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {}

AbstractQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::vector<std::string>& columns) noexcept {
    _column.insert(_column.end(), columns.begin(), columns.end());
    return *this;
}
AbstractQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) noexcept {
    _table = table;
    return *this;
}

AbstractQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& parametr) noexcept {
    _parametr.push_back(parametr);
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
    for (int i = 0; i < _parametr.size(); i++) {
        query += " " + _parametr[i];
        if (i < _parametr.size() - 1) {
            query += " AND";
        }
    }

    query += ";";
    return query;
}

