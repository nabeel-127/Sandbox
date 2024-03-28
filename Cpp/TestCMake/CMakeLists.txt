cmake_minimum_required(VERSION 3.0)

project(HelloWorld)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(HelloWorld src/main.cpp)