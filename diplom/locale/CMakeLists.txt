cmake_minimum_required(VERSION 3.20)
project(diplom)

set(CMAKE_CXX_STANDARD 17)

# Укажите путь к Boost
set(BOOST_ROOT "d:/gitrepo/boost_1_86_0")
set(CMAKE_PREFIX_PATH "${BOOST_ROOT}")

# Укажите директорию с библиотеками
link_directories("${BOOST_ROOT}/stage/lib")

# Укажите директории для поиска заголовочных файлов
#include_directories("${BOOST_ROOT}/include")

# Найдите необходимые компоненты Boost
find_package(Boost 1.86.0 REQUIRED COMPONENTS locale system filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) # Включите директории Boost
    add_executable(${PROJECT_NAME} indexator.cpp) # Создайте исполняемый файл
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES}) # Подключите библиотеки Boost
else()
    message(FATAL_ERROR "Boost not found!")
endif()
