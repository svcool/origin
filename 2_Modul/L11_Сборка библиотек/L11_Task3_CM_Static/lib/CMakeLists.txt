cmake_minimum_required(VERSION 3.22.0)
project(main_lib)
set(source_lib greeter.cpp greeter.h)
add_library(main_lib STATIC ${source_lib})