### ������� 3 (��������������)
���������� ������� ������ `SqlSelectQueryBuilder`, ������� ������ ��������� � ������� `FROM` ������� �������������� ��������� ������� � �������.
������ ���� � ����� �������:
```
AdvancedSqlSelectQueryBuilder query_builder;
query_builder.AddColumns({"name", "phone"});
query_builder.AddFrom("students");
query_builder.<SomeMethod>(...); // ��������� ������� id > 42
static_assert(query_builder.BuildQuery(), 
                "SELECT name, phone FROM students WHERE id>42;");
```

------