# Домашнее задание к занятию «Структурные шаблоны: Proxy, Decorator, Adapter»

### Задание 2

В дополнение к классам-заместителям `VeryHeavyDatabase`, реализованным на лекции, реализуйте класс
```
class OneShotDB : VeryHeavyDatabase {
  explicit OneShotDB (VeryHeavyDatabase* real_object, size_t shots=1) : ...
}
```
Он должен возвращать данные по ключу из реального объекта то количество раз, которое указано в конструкторе.
Исчерпав лимит получения данных, метод `GetData` всегда возвращает строку error.
Пример использования:
```
auto real_db = VeryHeavyDatabase();
auto limit_db = OneShotDB(std::addressof(real_db), 2);
std::cout << limit_db.GetData("key") << std::endl;
std::cout << limit_db.GetData("key") << std::endl;
std::cout << limit_db.GetData("key") << std::endl;

Output:
>>> value
>>> value
>>> error
```

------

### Правила приёма домашней работы

Прикрепите в личном кабинете ссылку на ваш репозиторий.

### Критерии оценки домашней работы

1. В личном кабинете прикреплена ссылка на репозиторий с кодом для заданий 1 и 2.
2. По ссылке содержится код, который компилируется и при запуске выполняет описанные в задании задачи.
