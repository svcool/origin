cmake_minimum_required(VERSION 3.5)

project(PreUDPsocket VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 COMPONENTS Widgets network REQUIRED)



set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        udpworker.h
        udpworker.cpp
)


qt_add_executable(PreUDPsocket
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)


target_link_libraries(PreUDPsocket PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)


if(QT_VERSION_MAJOR EQUAL 6)

qt_finalize_executable(PreUDPsocket)
endif()
