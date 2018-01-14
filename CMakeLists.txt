cmake_minimum_required(VERSION 2.8)
project(foas_common)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

include_directories(
  include)

file(GLOB_RECURSE LIB_SRC src/common FOLLOW_SYMLINKS *.cpp)
add_library(${PROJECT_NAME}
  ${LIB_SRC})
