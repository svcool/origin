#include <cassert>
#include "Query.h"
#include "exception.h"

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        SqlSelectQueryBuilder query_builder;

        query_builder.AddColumn("name").AddColumn("phone");
        query_builder.AddFrom("students");
        query_builder.AddWhere("id", "42").AddWhere("name", "John");
        std::cout << query_builder.BuildQuery();
    
        assert(query_builder.BuildQuery() == "SELECT name, phone FROM students WHERE id=42 AND name=John;");
    }
    catch (const QueryException& err) {
        std::cout << "Error: " << err.what() << std::endl;
    }
       // обработка остальных исключений
    catch (const std::exception&) {
        std::cout << "Something wrong" << std::endl;
    }
    
    return 0;
}