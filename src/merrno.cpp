// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "merrno.h"

using std::to_string;

void merrno::help() {
    std::cout << "merrno [-h|--help]"
                 "  Displays the end code of the last program or command, and code of error" << std::endl;
}

int merrno::get_code() {
    return code;
}

int merrno::get_errno_code() {
    return errno_code;
}

void merrno::get_description() {
    switch (code) {
        case 0:
            std::cout << "Everything was done without errors." << std::endl;
            return;
        case -1:
            std::cout << "Error with mcd function.";
            break;
        case -2:
            std::cout << "Error with mpwd function.";
            break;
        case -3:
            std::cout << "Error with exit function.";
            break;
        case -4:
            std::cout << "Error with mecho function.";
            break;
        case -5:
            std::cout << "Error with mexport function.";
            break;
        default:
            std::cout << "Unknown error with code " << code << ". And errno code " << errno_code << "." << std::endl;
            return;
    }
    std::cout << "Errno code " << errno_code << "." << std::endl;
}

void merrno::set_code(int new_code, int new_errno_code) {
    code = new_code;
    errno_code = new_errno_code;
}
