cmake_minimum_required(VERSION 3.15)
project(myshell)

set(CMAKE_CXX_STANDARD 17)


find_library(Readline_LIBRARY NAMES readline)
add_executable(myshell src/main.cpp src/Input.cpp includes/Input.h src/wildcard_parser.cpp includes/wildcard_parser.h src/merrno.cpp includes/merrno.h src/my_functions.cpp includes/my_functions.h src/my_programs.cpp includes/my_programs.h src/helpers.cpp includes/helpers.h src/VariablesManager.cpp includes/VariablesManager.h)
add_executable(mycat src/mycat.cpp src/low_level.cpp includes/low_level.h src/high_level.cpp includes/high_level.h)
include_directories(includes)
target_link_libraries(myshell readline)