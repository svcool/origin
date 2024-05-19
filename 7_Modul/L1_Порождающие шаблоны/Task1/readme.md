# �������� ������� � ������� ������������ ��������

�������� ��� �������, �� ��������� ������������ ������ Builder ��� ������������ �����.

### ���� �������

1. ��������� ������������ ������ Builder ��� ���������� ������� SQL-��������.

### ���������� � ���������� ��������� �������
1. ��� ���������� ������� � ����������� ����� ����� ��������� � ������������ �������� Windows, macOS ��� Linux � ������������� �� �� Microsoft Visual Studio 2022 ��� ����� ������ IDE, ������� ��� ���������� ���������� �������� �� C++.
2. ������� �� [GitHub](https://github.com/). [���������� �� ����������� �� GitHub](https://github.com/netology-code/cppm-homeworks/tree/main/common/sign%20up).

### ���������� �� ���������� ��������� �������

[���������� ���� �� ������](https://github.com/netology-code/cppm-homeworks/blob/main/common/readme.md).

------

### ������� 1

���������� ����� `SqlSelectQueryBuilder`, ������� ����� ������������ ��� ����������
������� SELECT-��������.

������ ������������� ������:
```
#inclide "sql_query_builder.h"

int main {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    
    static_assert(query_builder.BuildQuery(), 
                    "SELECT name, phone FROM students WHERE id=42 AND name=John;");
}
```
#### �������� �������� �� ��������� �������
1. ������ ���������� ������� `AddColumn, AddFrom, AddWhere` ����� �������� � ����� �������. ��� ���� ������ ������ ������ ��������� ���������.
2. ���� ����� `AddColumn` �� ��� ������, ������ ������ ���������� � `SELECT * ...`.
3. ��� �������� ������ � ������� ����� ���� �� �������� ���������, ��� � �������.
4. ������ `AddFrom` ������ �������������� �������� ������� � ������.
5. �� �������� `;` � ����� ������� �������.

------

### ������� 2
��������� ����� �� ����������� ������� ������� 
```
SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
```
� ������� �������� ����� ����� �������� � ������ ����� ��������� �������.

��������� ����� �� ����������� ������� ������� 
```
SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
```
� ������� ����� ������ ����� �������� � ������ ����� ��������� �����, �� ������� �� ����� ��������� ������ ������, ��� � ������� ��������.

---

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

### ������� ����� �������� ������

����� ����� �������� �������, ���������� � ������ �������� ������ �� ��� �����������.

### �������� ������ �������� ������

1. � ������ �������� ����������� ������ �� ����������� � ����� ��� ������� 1 � 2.
2. �� ������ ���������� ���, ������� ������������� � ��� ������� ��������� ��������� � ������� ������.