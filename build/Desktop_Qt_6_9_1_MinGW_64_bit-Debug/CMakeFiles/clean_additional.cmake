# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Qtbank_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Qtbank_autogen.dir\\ParseCache.txt"
  "Qtbank_autogen"
  )
endif()
