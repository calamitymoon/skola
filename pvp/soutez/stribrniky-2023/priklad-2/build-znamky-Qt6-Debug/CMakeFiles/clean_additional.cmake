# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/znamky_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/znamky_autogen.dir/ParseCache.txt"
  "znamky_autogen"
  )
endif()
