cmake_minimum_required(VERSION 3.20)
set(PostgreSQL_ADDITIONAL_VERSIONS "16") # указываем версию PQ
project(Project1)#имя проекта
add_executable(Project1 main.cpp) # указываем исполняемый файл 
#add_subdirectory("d:\\Program Files\\MyProject\\origin\\libpqxx-7.9.0" pqxx_build) # Укажите путь к libpq++
add_subdirectory("d:\\gitrepo\\libpqxx-7.9.0\\" pqxx_build) # Укажите путь к libpq++
target_compile_features(Project1 PRIVATE cxx_std_20) # Включите C++17
target_link_libraries(Project1 pqxx) # Слинкуйте libpq++ к проекту