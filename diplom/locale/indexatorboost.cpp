#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <boost/locale.hpp>

using namespace std;

string clean_html(const string& html) {
    // Удаление HTML-тегов
    return regex_replace(html, regex(R"(<[^>]*>)"), "");
}

string remove_punctuation_and_whitespace(const string& text) {
    // Удаление знаков препинания и лишних пробелов
    string cleaned_text = regex_replace(text, regex(R"([\s]+)"), " "); // Замена нескольких пробелов на один
    cleaned_text = regex_replace(cleaned_text, regex(R"([.,!?;:'\"(){}[\]<>]|\n|\t)"), ""); // Удаление знаков препинания
    return cleaned_text;
}

string to_lowercase(const string& text) {
    return boost::locale::to_lower(text);
}

int main6() {
    // Инициализация локали Boost
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    boost::locale::generator gen;
    std::locale loc = gen("en_US.UTF-8"); // Замените на вашу локаль
    std::locale::global(loc);

    // Открытие HTML файла
    ifstream file("xgconsole.xml");
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return 1;
    }

    // Чтение содержимого файла
    string html((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Очистка HTML
    string no_html = clean_html(html);

    // Удаление знаков препинания и пробелов
    string cleaned_text = remove_punctuation_and_whitespace(no_html);

    // Проверка на пустоту очищенного текста
    if (cleaned_text.empty()) {
        cerr << "Очищенный текст пуст!" << endl;
        return 1; // Или обработайте ошибку другим способом
    }

    // Преобразование текста в нижний регистр
    string final_text;
    try {
        final_text = to_lowercase(cleaned_text);
    }
    catch (const std::exception& e) {
        cerr << "Ошибка при преобразовании текста в нижний регистр: " << e.what() << endl;
        return 1;
    }

    // Вывод результата
    cout << "Очищенный текст:" << endl;
    cout << final_text << endl;

    return 0;
}
