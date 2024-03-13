cmake_minimum_required(VERSION 3.27)
project(chip-8 VERSION 1.0)
add_executable(chip8 src/main.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
target_include_directories(chip8 PUBLIC_HEADER
                             "${PROJECT_BINARY_DIR}/src")