# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\qtwidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\qtwidget_autogen.dir\\ParseCache.txt"
  "qtwidget_autogen"
  )
endif()
