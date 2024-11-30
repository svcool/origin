#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <locale>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

string clean_and_process_text(const string& html) {
    string no_nbsp = regex_replace(html, regex(R"(&[^;\s]*;)", regex::icase), " ");  // Заменяем &nbsp; на пробел, игнорируя регистр
    
    string no_scripts = regex_replace(no_nbsp, regex(R"(<(script|style|code|noscript|a|button)[^>]*>[\s\S]*?</\1>|<input[^>]*\/?>)", regex::icase), " ");// Удаление скриптов
    string no_html = regex_replace(no_scripts, regex(R"(<[^>]*>)"), " "); 
    // Удаление HTML-тегов  
    string cleaned_text = regex_replace(no_html, regex(R"([.,!?;:'\"(){}[\]<>]|\n|\t)"), " "); // Удаление знаков препинания
    cleaned_text = regex_replace(cleaned_text, regex(R"([\s]+)"), " "); // Замена нескольких пробелов на один
    // Преобразование текста в нижний регистр
    transform(cleaned_text.begin(), cleaned_text.end(), cleaned_text.begin(),
        [](unsigned char c) { return std::tolower(c); });
    cleaned_text.erase(cleaned_text.begin(), find_if(cleaned_text.begin(), cleaned_text.end(), [](unsigned char c) { return !isspace(c); }));
    cleaned_text.erase(find_if(cleaned_text.rbegin(), cleaned_text.rend(), [](unsigned char c) { return !isspace(c); }).base(), cleaned_text.end());

    // Фильтрация слов по длине
    istringstream iss(cleaned_text);
    string word;
    string filtered_text;

    while (iss >> word) {
        if (word.length() >= 3 && word.length() <= 32) {
            filtered_text += word + " "; // Добавляем пробел после слова
        }
    }
    if (!filtered_text.empty()) {
        filtered_text.pop_back(); // Удаляем последний пробел
    }
    return filtered_text;
}

int main33() {
    setlocale(LC_ALL, "Russian");
    //system("chcp 65001");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream file("xgconsole.xml");
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла!" << endl;
        return 1;
    }

    // Чтение содержимого файла
    string html((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Очистка и обработка текста
    string cleaned_text = clean_and_process_text(html);

    // Проверка на пустоту очищенного текста
    if (cleaned_text.empty()) {
        cerr << "Очищенный текст пуст!" << endl;
        return 1; // Или обработайте ошибку другим способом
    }

    // Вывод результата
    cout << "Очищенный текст:" << endl;
    cout << cleaned_text << endl;

    return 0;
}
