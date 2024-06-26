﻿# Домашнее задание к занятию «C++ и БД. ORM»

Выполнив это задание, вы сможете использовать библиотеку wbto для манипуляции записями и таблицами с помощью ORM-классов.

### Цель задания

1. Научиться создавать ORM-классы и связи между ними в С++ в соответствии со схемой базы данных.
2. Научиться использовать ORM-классы для добавления и получения данных.

### Инструкция для выполнения домашнего задания

<details>

<summary>Прочитать инструкцию</summary>

Вам встретятся два типа заданий в домашней работе:

- без звёздочки,
- со звёздочкой (*).

Задания без звёздочки нужно обязательно выполнить, чтобы получить зачёт.

Задания со звёздочкой — это задания дополнительные или повышенной сложности. Выполнять их не обязательно, но работа над ними поможет глубже понять тему.

Домашнее задание состоит из 1–3 заданий для самостоятельного решения. Чтобы их решить, нужны как знания, которые вы получили на вебинаре или из видео, так и навык поиска информации в интернете — самый важный навык программиста.

Любые вопросы по решению задач задавайте преподавателю в чате курса.

</details>

-----

### Задание 1

Напишите ORM-классы, используя библиотеку **wtdbo**, по схеме:

![](book_publishers_scheme.png)   

Интуитивно нужно выбрать подходящие типы и связи полей.

------

### Задание 2

Используя библиотеку **wtdbo**, составьте запрос выборки магазинов, продающих целевого издателя.

Напишите программу на C++, которая:

- подключается к PostgreSQL;
- создаёт все необходимые таблицы и связи между ними;
- заполняет таблицы тестовыми данными из С++ кода. Данные для заполнения выберите произвольно;
- выводит информацию об издателе (publisher), имя или идентификатор которого принимается через `std::cin`. Программа должна выводить список магазинов, в которых продают книги этого издателя.

------

### Правила приёма домашней работы

Чтобы сдать домашнее задание, прикрепите в личном кабинете ссылку на ваш репозиторий.

### Критерии оценки домашней работы

1. В личном кабинете прикреплена ссылка на репозиторий с кодом для заданий 1 и 2.
2. В ссылке содержится код, который при запуске выполняет описанный в задании алгоритм.

