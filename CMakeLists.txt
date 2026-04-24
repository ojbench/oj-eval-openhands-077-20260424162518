

cmake_minimum_required(VERSION 3.10)
project(CrossArray)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the CrossArray library
add_library(CrossArray STATIC CrossArray.cpp)

# Create a test executable
add_executable(code main.cpp)

# Create comprehensive test executable
add_executable(test_comprehensive test_comprehensive.cpp)

# Link the library
target_link_libraries(code CrossArray)
target_link_libraries(test_comprehensive CrossArray)

