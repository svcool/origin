//#include "pugixml.hpp"
//#include <iostream>
//#include <globals.h>
//int main() {
//
//     //setlocale(LC_ALL, "Russian");
//    //system("chcp 1251");
//    SetConsoleCP(CP_UTF8);
//    SetConsoleOutputCP(CP_UTF8);
//    pugi::xml_document doc;
//
//    // Загрузка XML-файла
//    if (!doc.load_file("xgconsole.xml")) {
//        std::cerr << "Error loading XML file!" << std::endl;
//        return -1;
//    }
//
//    // Выполнение XPath-запроса для получения всех элементов <a>
//    pugi::xpath_query query_links("//a");
//    pugi::xpath_node_set links = query_links.evaluate_node_set(doc);
//
//    std::cout << "Found links to other pages:" << std::endl;
//    for (size_t i = 0; i < links.size(); ++i) {
//        // Получаем узел <a>
//        pugi::xml_node a_node = links[i].node();
//
//        // Получаем значение атрибута href
//        const char* href_value = a_node.attribute("href").value();
//
//        // Проверяем, есть ли атрибут href
//        if (href_value && *href_value) {
//            std::cout << "Href: " << href_value << std::endl; // Вывод значения атрибута href
//        }
//        else {
//            std::cout << "Href attribute is missing or empty for this <a> element." << std::endl;
//        }
//
//        // Выводим содержимое узла <a>
//        std::cout << "Node content: " << a_node.child_value() << std::endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <globals.h>
#include <cstdlib> // Для system()
using namespace std;

int main133() {
     setlocale(LC_ALL, "Russian");
    //system("chcp 1251");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    // Задайте доменное имя
    string domain = "https://example.com"; // Замените на ваше доменное имя
    // Открытие HTML файла
    ifstream file("xgconsole.xml");
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return 1;
    }

    // Чтение содержимого файла
    string html((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Регулярное выражение для поиска ссылок в атрибуте href
    regex href_regex(R"(<a\s+[^>]*href=["']((http://[^"']+)|(https://[^"']+)|(/[^"']+))["'][^>]*>)");
    smatch match;

    vector<string> links;

    // Поиск всех совпадений
    string::const_iterator searchStart(html.cbegin());
    while (regex_search(searchStart, html.cend(), match, href_regex)) {
        string link = match[1]; // Сохраняем найденную ссылку

        // Проверка, является ли ссылка относительной
        if (link[0] == '/') {
            link = domain + link; // Преобразуем в полный формат
        }

        links.push_back(link); // Сохраняем ссылку
        searchStart = match.suffix().first; // Продолжаем поиск
    }

    // Вывод найденных ссылок
    cout << "dsfdsfвааываы" << endl;
    for (const auto& link : links) {
        cout << link << endl;
    }

    return 0;
}