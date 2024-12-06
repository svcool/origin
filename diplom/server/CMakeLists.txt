cmake_minimum_required(VERSION 3.20)

# Политика CMake
if (POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

add_definitions(-D_WIN32_WINNT=0x0601 -DWINVER=0x0601)

# Переменная для проекта
set(project "httpserver")
project(${project})

# Указываем версию PQ
set(PostgreSQL_ADDITIONAL_VERSIONS "16")

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем директории для заголовочных файлов
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Копирование необходимых файлов в каталог сборки
set(INI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/settings.ini" "${CMAKE_CURRENT_SOURCE_DIR}/gooyagl_logo.png" "${CMAKE_CURRENT_SOURCE_DIR}/index.html")

foreach(INI_FILE ${INI_FILES})
    get_filename_component(FILE_NAME ${INI_FILE} NAME)
    set(TARGET_FILE ${CMAKE_BINARY_DIR}/${FILE_NAME})

    if(NOT EXISTS ${TARGET_FILE})
        if(EXISTS ${INI_FILE})
            configure_file(${INI_FILE} ${TARGET_FILE} COPYONLY)
        else()
            message(FATAL_ERROR "Source file not found: ${INI_FILE}")
        endif()
    else()
        message(STATUS "File already exists, skipping: ${TARGET_FILE}")
    endif()
endforeach()

# Добавление исполняемого файла для HTTP-сервера
add_executable(${project} "src/main.cpp" "src/httpserver.cpp" "src/bd.cpp" "src/parserini.cpp")

# Подключение библиотеки libpqxx
add_subdirectory("../../../libpqxx-7.9.0/" pqxx_build)

# Путь к Boost
set(BOOST_ROOT "../../../boost_1_86_0/") # Укажите путь к вашей установке Boost

# Поиск библиотек
find_package(Boost 1.86.0 REQUIRED COMPONENTS)

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost not found!")
endif()

# Подключение библиотек
if(Boost_FOUND)
    target_include_directories(${project} PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(${project} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} pqxx)

    message(STATUS "Found BOOST ${Boost_VERSION_STRING}")
else()
    message(FATAL_ERROR "Boost Not Found") # Остановка сборки при ошибке
endif()