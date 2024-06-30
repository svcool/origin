cmake_minimum_required(VERSION 3.5)

project(05_SignalSlot VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)



set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        signals.h
        signals.cpp
)

qt_add_executable(05_SignalSlot
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)


target_link_libraries(05_SignalSlot PRIVATE Qt6::Widgets)


qt_finalize_executable(05_SignalSlot)

