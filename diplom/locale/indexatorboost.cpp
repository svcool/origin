#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <boost/locale.hpp>
#include <windows.h>

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

int main() {
    // Инициализация локали Boost
    //setlocale(LC_ALL, "Russian");
    system("chcp 65001");
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    boost::locale::generator gen;
    std::locale loc = gen("ru_RU.UTF-8"); // Замените на вашу локаль
    std::locale::global(loc);

    ifstream file("xgconsole.xml"); // Открытие HTML файла
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return 1;
    }
    string html((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());    // Чтение содержимого файла
    file.close();
    string no_html = clean_html(html); // Очистка HTML
    string cleaned_text = remove_punctuation_and_whitespace(no_html);// Удаление знаков препинания и пробелов
    if (cleaned_text.empty()) {
        cerr << "Очищенный текст пуст!" << endl;
        return 1; // Или обработайте ошибку другим способом
    }
    string final_text;
    try {
        final_text = to_lowercase(cleaned_text);
    }
    catch (const std::exception& e) {
        cerr << "Ошибка при преобразовании текста в нижний регистр: " << e.what() << endl;
        return 1;
    }
    cout << "Очищенный текст:" << endl;
    cout << final_text << endl;

    return 0;
}
