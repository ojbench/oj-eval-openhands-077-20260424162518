

cmake_minimum_required(VERSION 3.10)
project(CrossArray)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a test executable using the header-only implementation
add_executable(code main.cpp)

# Create comprehensive test executable
add_executable(test_comprehensive test_comprehensive.cpp)

