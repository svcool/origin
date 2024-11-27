// GLOBAL_VARIABLES_H
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H
#include <iostream>
#include <Windows.h>
#include <string>
#include <bd.h>
#include <except.h>
#include <ctime>
#include <chrono>
#include <fstream>

//#include <cstdio> // для временных файлов
#include <filesystem>

// Структура для хранения ссылки и частоты
struct SearchResult {
    std::string url;
    std::string title;
    int frequency;
};

#endif // GLOBAL_VARIABLES_H