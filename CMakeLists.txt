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

file(GLOB_RECURSE LIB_SRC FOLLOW_SYMLINKS src/common/*.cpp)
add_library(${PROJECT_NAME}
  ${LIB_SRC})

target_link_libraries(${PROJECT_NAME}
  json-c)

add_custom_target(prepare-json-c-environment
  COMMAND cd ${PROJECT_SOURCE_DIR} && git submodule update --init --recursive && cd 3rdparty/json-c && sh autogen.sh && cd -)

add_dependencies(json-c
  prepare-json-c-environment)

macro(enableGTesting)
  include(ExternalProject)
  
  if(NOT TARGET gtest)
    ExternalProject_Add(gtest
      URL https://github.com/google/googletest/archive/release-1.8.0.tar.gz
      
      PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
      INSTALL_COMMAND "")
  endif()
  ExternalProject_Get_Property(gtest source_dir binary_dir)
  
  enable_testing()
  
  file(GLOB_RECURSE TEST_SRC FOLLOW_SYMLINKS src/test/*.cpp)
  add_executable(${PROJECT_NAME}-runUnitTests ${TEST_SRC})
  target_link_libraries(${PROJECT_NAME}-runUnitTests ${PROJECT_NAME})
  
  add_dependencies(${PROJECT_NAME}-runUnitTests
    gtest)
  
  include_directories(
    BEFORE ${source_dir}/googletest/include)
  
  target_link_libraries(${PROJECT_NAME}-runUnitTests
    ${binary_dir}/googlemock/gtest/libgtest.a
    ${binary_dir}/googlemock/gtest/libgtest_main.a
    pthread)
  
  add_test(
    NAME ${PROJECT_NAME}-runUnitTests
    COMMAND ${PROJECT_NAME}-runUnitTests)
endmacro()

enableGTesting()
