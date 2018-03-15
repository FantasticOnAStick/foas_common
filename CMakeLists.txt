cmake_minimum_required(VERSION 2.8)
project(foas_common)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

add_subdirectory(3rdparty)

include_directories(
  include
  ${PROJECT_SOURCE_DIR}/3rdparty/json-c)

file(GLOB_RECURSE LIB_SRC src/common FOLLOW_SYMLINKS *.cpp)
add_library(${PROJECT_NAME}
  ${LIB_SRC})

target_link_libraries(${PROJECT_NAME}
  json-c)

add_custom_target(prepare-json-c-environment
  COMMAND cd ${PROJECT_SOURCE_DIR} && git submodule update --init --recursive && cd 3rdparty/json-c && sh autogen.sh && cd -)

add_dependencies(json-c
  prepare-json-c-environment)
