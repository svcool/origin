# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\airport_manager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\airport_manager_autogen.dir\\ParseCache.txt"
  "airport_manager_autogen"
  )
endif()
