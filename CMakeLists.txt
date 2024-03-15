cmake_minimum_required(VERSION 3.27)
project(chip-8 VERSION 1.0)
add_executable(chip8 src/main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_library(source src/chip8.cpp)
target_link_libraries(chip8 PUBLIC source sfml-graphics sfml-window sfml-system)
target_include_directories(chip8 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")