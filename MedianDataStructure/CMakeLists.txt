cmake_minimum_required(VERSION 3.15)
project(MedianDataStructure)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES MedianHeap.cpp Google_tests/test.cpp)


add_executable(MedianDataStructure MedianHeap.cpp MedianHeap.h EmptyMedianException.h Google_tests/test.cpp main.cpp)

target_link_libraries(MedianDataStructure gtest gtest_main)