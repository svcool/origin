cmake_minimum_required(VERSION 3.20)
if (POLICY CMP0074)
    cmake_policy (SET CMP0074 NEW)
endif()

set(PostgreSQL_ADDITIONAL_VERSIONS "16") # Указываем версию PQ

project(diplom) # Имя проекта

# Указываем исполняемый файл 
add_executable(diplom main.cpp)

# Укажите путь к libpq++
add_subdirectory("d:\\gitrepo\\libpqxx-7.9.0\\" pqxx_build)

# Укажите путь к pugixml
add_subdirectory("d:\\gitrepo\\pugixml-1.14\\" pugixml_build)

# Путь к Boost
set(BOOST_ROOT "d:/gitrepo/boost_1_86_0/") # Укажите путь к вашей установке Boost
set(BOOST_INCLUDEDIR ${BOOST_ROOT}) # Укажите путь к заголовкам Boost
add_library(boost_beast INTERFACE)
add_library(Boost::beast ALIAS boost_beast)
target_include_directories(boost_beast INTERFACE include)
target_link_libraries(boost_beast
  INTERFACE
    Boost::asio
    Boost::assert
    Boost::bind
    Boost::config
    Boost::container
    Boost::core
    Boost::endian
    Boost::intrusive
    Boost::logic
    Boost::mp11
    Boost::optional
    Boost::smart_ptr
    Boost::static_assert
    Boost::static_string
    Boost::system
    Boost::throw_exception
    Boost::type_traits
    Boost::utility
    Boost::winapi
)
#if(MINGW)
#    link_libraries(ws2_32 wsock32)
#endif()

# Включите директории с заголовками Boost
include_directories(${BOOST_INCLUDEDIR})

# Найдите библиотеку Boost с необходимыми компонентами
find_package(Boost REQUIRED COMPONENTS program_options REQUIRED)

if(Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    #target_include_directories(diplom PUBLIC ${Boost_INCLUDE_DIRS}) # Используйте Boost_INCLUDE_DIRS
    #target_link_libraries(diplom ${Boost_LIBRARIES}) # Используйте Boost_LIBRARIES
    message(STATUS "Found BOOST ${Boost_VERSION_STRING}")
else()
    message(FATAL_ERROR "Boost Not Found") # Изменено на FATAL_ERROR для остановки сборки при ошибке
endif()

# Подключите директории с заголовками pugixml
target_include_directories(diplom PRIVATE "d:\\gitrepo\\pugixml-1.14\\include") # Убедитесь, что путь правильный

# Слинкуйте pugixml к вашему проекту
target_link_libraries(diplom pqxx pugixml)

target_compile_features(diplom PRIVATE cxx_std_17) # Включите C++17
