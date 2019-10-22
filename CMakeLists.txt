cmake_minimum_required(VERSION 3.15)
project(myshell)

set(CMAKE_CXX_STANDARD 17)


find_library(Readline_LIBRARY NAMES readline)
add_executable(mycat mycat/mycat.cpp mycat/low_level.cpp mycat/low_level.h mycat/high_level.cpp mycat/high_level.h)

include_directories(includes)
add_executable(myshell src/main.cpp src/Input.cpp src/wildcard_parser.cpp src/merrno.cpp includes/merrno.h
        src/my_functions.cpp src/my_programs.cpp src/helpers.cpp src/VariablesManager.cpp)
target_link_libraries(myshell readline)