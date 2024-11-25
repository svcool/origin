// GLOBAL_VARIABLES_H
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H
#include <iostream>
#include <Windows.h>
#include <string>
#include <bd.h>
#include <except.h>

// —труктура дл€ хранени€ ссылки и частоты
struct SearchResult {
    std::string url;
    int frequency;
};

#endif // GLOBAL_VARIABLES_H