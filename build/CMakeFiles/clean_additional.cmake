# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appLogAnalizer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appLogAnalizer_autogen.dir\\ParseCache.txt"
  "appLogAnalizer_autogen"
  )
endif()
