# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "09_UDPsocket_autogen"
  "CMakeFiles\\09_UDPsocket_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\09_UDPsocket_autogen.dir\\ParseCache.txt"
  )
endif()
