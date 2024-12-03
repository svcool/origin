cmake_minimum_required(VERSION 3.20)

# Название проекта
project(diplom)

add_definitions(-D_WIN32_WINNT=0x0601 -DWINVER=0x0601)
# Установка пути к Boost
set(BOOST_ROOT "../../../boost_1_86_0/") # Укажите корректный путь к Boost
set(CMAKE_PREFIX_PATH "${BOOST_ROOT}")
set(OPENSSL_ROOT_DIR "../../../OpenSSL")
# Включение пользовательских заголовков
include_directories(include)

# Укажите исходный файл
add_executable(${PROJECT_NAME} "httpclient.cpp")

# Настройка Boost
find_package(Boost 1.86 REQUIRED COMPONENTS system thread) # Укажите требуемые модули Boost
find_package(OpenSSL REQUIRED)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost not found!")
endif()

if (MSVC)  # Только для Windows
    add_compile_definitions(BOOST_ASIO_USE_WINDOWS_SSPI)
    message(STATUS "Using SChannel (Windows SSPI) for SSL/TLS")
    
    # Добавляем флаг /bigobj для решения ошибки C1128
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()

# Подключение Boost к проекту
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
 
# Вывод диагностической информации
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Project: ${PROJECT_NAME}")
