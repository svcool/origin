cmake_minimum_required(VERSION 3.22.0)
#project(Test)
#set (source_exe List.cpp main.cpp)
#add_executable(Test ${source_exe})

add_subdirectory(./catch2 Catch2-build)
add_executable(MyProject List.cpp test-main.cpp)
target_link_libraries(MyProject PRIVATE Catch2::Catch2)