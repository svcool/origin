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

AbstractQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
    for (const auto n : kv) {
        _conditions[n.first] = n.second;
    }
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
    for (auto it = _conditions.begin(); it != _conditions.end(); ++it) {
        query += " " + it->first + "=" + it->second;
        if (next(it) != _conditions.end()) {
            query += " AND";
        }
    }

    query += ";";
    return query;
}

