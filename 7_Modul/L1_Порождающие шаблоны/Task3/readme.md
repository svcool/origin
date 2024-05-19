### Задание 3 (необязательное)
Реализуйте потомок класса `SqlSelectQueryBuilder`, который сможет добавлять в условие `FROM` запроса дополнительные операторы «больше» и «меньше».
Пример кода с таким классом:
```
AdvancedSqlSelectQueryBuilder query_builder;
query_builder.AddColumns({"name", "phone"});
query_builder.AddFrom("students");
query_builder.<SomeMethod>(...); // Добавляем условие id > 42
static_assert(query_builder.BuildQuery(), 
                "SELECT name, phone FROM students WHERE id>42;");
```

------