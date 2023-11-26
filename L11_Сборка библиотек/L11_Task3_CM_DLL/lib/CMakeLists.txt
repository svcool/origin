cmake_minimum_required(VERSION 3.22.0)
#имя проекта
project(main_lib)
#задать список source_dll файлов
#для windows - подключает для exporta все функции библиотеки
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(source_dll leaver.cpp leaver.h)
#shared - динамическая библиотека, STATIC - статическая задаем имя создаваемой библиотеки и указываем список
add_library(main_dll SHARED ${source_dll})