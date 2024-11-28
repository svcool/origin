#ifndef INDEXATOR_H
#define INDEXATOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <map>
#include <vector>

// ***************************************************************************************
// Функция для очистки и обработки текста
std::string clean_and_process_text(const std::string& html);
// ***************************************************************************************
// Функция для подсчета частоты слов в тексте
std::map<std::string, int> countWordFrequency(const std::string& text);
// ***************************************************************************************
// Функция извлечения html ссылок
std::vector<std::string> extractLinks(const std::string& html, const std::string& domain);
// ***************************************************************************************
#endif //INDEXATOR_H