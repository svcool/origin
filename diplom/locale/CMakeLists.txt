cmake_minimum_required(VERSION 3.20)

#�������� CMake
if (POLICY CMP0074)
    cmake_policy (SET CMP0074 NEW)
endif()

#add_subdirectory(src)
include_directories(include)
set(project "diplom")
project(${project})


set(CMAKE_PREFIX_PATH "${BOOST_ROOT}")
set(BOOST_ROOT "../../../boost_1_86_0")
add_executable(${project}  "indexatorboost.cpp")
# ������� ���������� � ������������
link_directories("${BOOST_ROOT}/stage/lib")

# ������� ����������� ���������� Boost
find_package(Boost 1.86.0 REQUIRED COMPONENTS locale system filesystem)

if (Boost_FOUND)
    target_include_directories(${project} PUBLIC ${Boost_INCLUDE_DIRS}) # �������� ���������� Boost

    target_link_libraries(${project} ${Boost_LIBRARIES}) # ���������� ���������� Boost
else()
    message(FATAL_ERROR "Boost not found!")
endif()


