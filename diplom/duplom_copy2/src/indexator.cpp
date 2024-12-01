#include "indexator.h"
//********************************************************************************************************************
   std::string clean_and_process_text(const std::string& html) {
    // Заменяем &nbsp; на пробел, игнорируя регистр
    std::string no_nbsp = std::regex_replace(html, std::regex(R"(&[^;\s]*;)", std::regex::icase), " ");

    // Удаление скриптов и стилей
    std::string no_scripts = std::regex_replace(no_nbsp, std::regex(R"(<(script|style|code|noscript|a|button)[^>]*>[\s\S]*?</\1>|<input[^>]*\/?>)", std::regex::icase), " ");

    // Удаление HTML-тегов
    std::string no_html = std::regex_replace(no_scripts, std::regex(R"(<[^>]*>)"), " ");

    // Удаление знаков препинания и лишних пробелов
    std::string cleaned_text = std::regex_replace(no_html, std::regex(R"([.,!?;:'\"(){}[\]<>-]|[\n\t])"), " ");
    cleaned_text = std::regex_replace(cleaned_text, std::regex(R"([\s]+)"), " ");

    // Преобразование текста в нижний регистр
    std::transform(cleaned_text.begin(), cleaned_text.end(), cleaned_text.begin(),
        [](unsigned char c) { return std::tolower(c); });

    // Удаление лишних пробелов в начале и конце строки
    cleaned_text.erase(cleaned_text.begin(), std::find_if(cleaned_text.begin(), cleaned_text.end(), [](unsigned char c) { return !std::isspace(c); }));
    cleaned_text.erase(std::find_if(cleaned_text.rbegin(), cleaned_text.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), cleaned_text.end());

    // Фильтрация слов по длине
    std::istringstream iss(cleaned_text);
    std::string word;
    std::string filtered_text;

    while (iss >> word) {
        if (word.length() >= 3 && word.length() <= 32) {
            filtered_text += word + " "; // Добавляем пробел после слова
        }
    }

    // Удаляем лишний пробел в конце
    if (!filtered_text.empty()) {
        filtered_text.pop_back(); // Удаляем последний пробел
    }

    return filtered_text;
}
//********************************************************************************************************************
// Функция для подсчета частоты слов в тексте
std::map<std::string, int> countWordFrequency(const std::string& text) {
    std::map<std::string, int> word_freq; // Создаем карту для хранения слов и их частот
    std::istringstream iss(text); // Используем istringstream для разбивки текста на слова
    std::string word;

    while (iss >> word) {
        // Увеличиваем частоту слова в карте
        ++word_freq[word];
    }

    return move(word_freq); // Возвращаем карту с частотами слов
}

//********************************************************************************************************************

std::vector<std::string> extractLinks(const std::string& html, const std::string& domain) {
    // Регулярное выражение для поиска ссылок в атрибуте href
    std::regex href_regex(R"(<a\s+[^>]*href=["']((http://[^"']+)|(https://[^"']+)|(/[^"']+))["'][^>]*>)");
    std::smatch match;

    std::vector<std::string> links;

    // Поиск всех совпадений
    std::string::const_iterator searchStart(html.cbegin());
    while (std::regex_search(searchStart, html.cend(), match, href_regex)) {
        std::string link = match[1]; // Сохраняем найденную ссылку

        // Проверка, является ли ссылка относительной
        if (link[0] == '/') {
            link = "http://" + domain + link; // Преобразуем в полный формат
        }

        links.push_back(link); // Сохраняем ссылку
        searchStart = match.suffix().first; // Продолжаем поиск
    }

    return move(links); // Возвращаем вектор найденных ссылок
}
//********************************************************************************************************************
std::pair<std::string, std::string> fixURL(const std::string& url) {

    std::string host;
    std::string target;
    std::string cleanUrl = std::regex_replace(url, std::regex(R"(^https?://)"), "");  // Удаляем протокол (http:// или https://)
    size_t pos = cleanUrl.find("/");// Находим позицию первого символа '/' после базового URL

    if (pos == std::string::npos) { // Если '/' не найден, значит, весь URL - это хост
        host = cleanUrl;
        target = "/";
    }
    else {
        // Извлекаем базовый URL и путь
        host = cleanUrl.substr(0, pos); // Извлекаем базовый URL и путь
        target = cleanUrl.substr(pos);   // Путь
    }
    return std::make_pair(host, target);
}
//*********************************************************************************************************************