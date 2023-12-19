cmake_minimum_required(VERSION 3.22.0)
#имя проекта
project(main_lib)
#задать список source_dll файлов
#для windows - подключает для exporta все функции библиотеки
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(sourceh_dll trian.h square.h rhombus.h rect.h r_trian.h quadr.h paral.h is_trian.h figure.h e_trian.h)
set(sourcecpp_dll trian.cpp square.cpp rhombus.cpp rect.cpp r_trian.cpp quadr.cpp paral.cpp is_trian.cpp figure.cpp e_trian.cpp)
#shared - динамическая библиотека, STATIC - статическая задаем имя создаваемой библиотеки и указываем список
add_library(main_dll SHARED ${sourceh_dll} ${sourcecpp_dll})