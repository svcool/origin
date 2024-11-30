cmake_minimum_required(VERSION 3.20)

set(project "diplom")
project(${project})
set(CMAKE_CXX_STANDARD 17)


set(CMAKE_PREFIX_PATH "${BOOST_ROOT}")
set(BOOST_ROOT "../../../boost_1_86_0/")
add_executable(${project}  "indexatorboost.cpp")
# Укажите директорию с библиотеками
link_directories("${BOOST_ROOT}/stage/lib")

# Найдите необходимые компоненты Boost
find_package(Boost 1.86.0 REQUIRED COMPONENTS locale system filesystem)

if (Boost_FOUND)
    target_include_directories(${project} PUBLIC ${Boost_INCLUDE_DIRS}) # Включите директории Boost
    
    target_link_libraries(${project} ${Boost_LIBRARIES}) # Подключите библиотеки Boost
else()
    message(FATAL_ERROR "Boost not found!")
endif()
