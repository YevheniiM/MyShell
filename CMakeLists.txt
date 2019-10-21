cmake_minimum_required(VERSION 3.15)
project(myshell)

set(CMAKE_CXX_STANDARD 17)


find_library(Readline_LIBRARY NAMES readline)
add_executable(myshell src/main.cpp src/Input.cpp includes/Input.h src/wildcard_parser.cpp includes/wildcard_parser.h src/helpers.cpp includes/helpers.h)
target_link_libraries(myshell readline)