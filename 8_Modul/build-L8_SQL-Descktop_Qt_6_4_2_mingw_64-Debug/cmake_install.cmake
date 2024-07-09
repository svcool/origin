<<<<<<< HEAD:8_Modul/08_SQL/08_DataBaseLect/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/cmake_install.cmake
# Install script for directory: D:/Program Files/MyProject/origin/origin/8_Modul/08_SQL/08_DataBaseLect
=======
# Install script for directory: D:/gitrepo/origin/8_Modul/L8_SQL
>>>>>>> 1:8_Modul/build-L8_SQL-Descktop_Qt_6_4_2_mingw_64-Debug/cmake_install.cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/08_DataBaseLect")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "D:/Qt/Tools/mingw1120_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD:8_Modul/08_SQL/08_DataBaseLect/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/cmake_install.cmake
file(WRITE "D:/Program Files/MyProject/origin/origin/8_Modul/08_SQL/08_DataBaseLect/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "D:/gitrepo/origin/8_Modul/build-L8_SQL-Descktop_Qt_6_4_2_mingw_64-Debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 1:8_Modul/build-L8_SQL-Descktop_Qt_6_4_2_mingw_64-Debug/cmake_install.cmake
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
