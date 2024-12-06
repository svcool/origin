cmake_minimum_required(VERSION 3.20)

#политика CMake
if (POLICY CMP0074)
    cmake_policy (SET CMP0074 NEW)
endif()

add_definitions(-D_WIN32_WINNT=0x0601 -DWINVER=0x0601)
include_directories(include)

# Указываем версию PQ
set(PostgreSQL_ADDITIONAL_VERSIONS "16") 

#переменная для проекта
set(project "diplom")
project(${project})

set(INI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/settings.ini")

foreach(INI_FILE ${INI_FILES})
    # Получаем имя файла
    get_filename_component(FILE_NAME ${INI_FILE} NAME)
    # Определяем целевой путь
    set(TARGET_FILE ${CMAKE_BINARY_DIR}/${FILE_NAME})

    # Проверяем, существует ли целевой файл
    if(NOT EXISTS ${TARGET_FILE})
        if(EXISTS ${INI_FILE})
            # Копируем файл в CMAKE_BINARY_DIR
            configure_file(${INI_FILE} ${TARGET_FILE} COPYONLY)
        else()
            message(FATAL_ERROR "Source file not found: ${INI_FILE}")
        endif()
    else()
        message(STATUS "File already exists, skipping: ${TARGET_FILE}")
    endif()
endforeach()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(${project}  "src/main.cpp" "src/tempfile.cpp" "src/httpclient.cpp" "src/indexator.cpp" "src/safequeue.cpp"  "src/bd.cpp" "src/parserini.cpp")

add_subdirectory("../../../libpqxx-7.9.0/" pqxx_build)

# Путь к Boost
set(BOOST_ROOT "../../../boost_1_86_0/") # Укажите путь к вашей установке Boost
set(OPENSSL_ROOT_DIR "../../../OpenSSL/")

find_package(Boost 1.86.0 REQUIRED COMPONENTS)
find_package(OpenSSL REQUIRED)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost not found!")
endif()

if(Boost_FOUND)
# подключаем заголовочные файлы всех директорий, где находятся заголовочные файлы для всех компонентов.System убирает предупреждения стороних библиотек
    #include_directories (SYSTEM ${Boost_INCLUDE_DIRS}) 
    target_include_directories(${project} PUBLIC ${Boost_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR}) # Используйте Boost_INCLUDE_DIRS
    target_link_libraries(${project} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} pqxx)
    message(STATUS "Found BOOST ${Boost_VERSION_STRING}")
else()
   message(FATAL_ERROR "Boost Not Found") # Изменено на FATAL_ERROR для остановки сборки при ошибке
endif()


