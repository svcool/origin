cmake_minimum_required(VERSION 3.20)

#политика CMake
if (POLICY CMP0074)
    cmake_policy (SET CMP0074 NEW)
endif()

#set(CONFIG_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h PARENT)
#add_subdirectory(src)
include_directories(include)
# Указываем версию PQ
set(PostgreSQL_ADDITIONAL_VERSIONS "16") 

#переменная для проекта
set(project "diplom")

#Имя проекта
project(${project})

# Указываем исполняемый файл 
add_executable(${project} "src/main.cpp" "src/bd.cpp" "include/bd.h" "include/globals.h")

# Путь к libpq++
#add_subdirectory("d:\\gitrepo\\libpqxx-7.9.0\\" pqxx_build)
add_subdirectory("d:/Program Files/MyProject/origin/libpqxx-7.9.0/" pqxx_build)

# Путь к pugixml
#add_subdirectory("d:\\gitrepo\\pugixml-1.14\\" pugixml_build)
add_subdirectory("d:/Program Files/MyProject/origin/pugixml-1.14/" pugixml_build)
# Путь к Boost
#set(BOOST_ROOT "d:/gitrepo/boost_1_86_0/") # Укажите путь к вашей установке Boost
set(BOOST_ROOT "d:/Program Files/MyProject/origin/boost_1_86_0/bin/x64") # Укажите путь к вашей установке Boost
#set(BOOST_INCLUDEDIR ${BOOST_ROOT}) # Укажите путь к заголовкам Boost
#set(Boost_LIBRARIES ${BOOST_ROOT}) # Укажите путь к заголовкам Boost
#add_library(boost_beast INTERFACE)
#add_library(Boost::beast ALIAS boost_beast)

#if(MINGW)
#    link_libraries(ws2_32 wsock32)
#endif()

# Найдите библиотеку Boost с необходимыми компонентами
find_package(Boost 1.86.0 REQUIRED COMPONENTS system coroutine regex)
#target_link_libraries(diplom Boost::date_time Boost::filesystem Boost::iostreams)
if(Boost_FOUND)
# подключаем заголовочные файлы всех директорий, где находятся заголовочные файлы для всех компонентов.System убирает предупреждения стороних библиотек
    #include_directories (SYSTEM ${Boost_INCLUDE_DIRS}) 
    target_include_directories(${project} PUBLIC ${Boost_INCLUDE_DIRS}) # Используйте Boost_INCLUDE_DIRS
    #target_link_libraries(${project} ${Boost_LIBRARIES}) # Связывание с библиотеками Boost
    target_link_libraries(${PROJECT_NAME} Boost::regex)
    message(STATUS "Found BOOST ${Boost_VERSION_STRING}")
else()
   message(FATAL_ERROR "Boost Not Found") # Изменено на FATAL_ERROR для остановки сборки при ошибке
endif()

# Подключите директории с заголовками pugixml
#target_include_directories(diplom PRIVATE "d:/Program Files/MyProject/origin/pugixml-1.14/include") # Убедитесь, что путь правильный
target_compile_features(${project} PRIVATE cxx_std_17) # Включите C++17
# Слинкуйте pugixml к вашему проекту
target_link_libraries(${project} pqxx pugixml)


