//
// Created by vorumbo on 21.10.19.
//

#include <iostream>
#include "merrno.h"

using std::to_string;

void merrno::help() {
    std::cout << "merrno [-h|--help]"
                 "  Displays the end code of the last program or command" << std::endl;
}

int merrno::get_code() {
    return code;
}

void merrno::get_description() {
    switch (code) {
        case 0:
            std::cout << "Everything was done without errors." << std::endl;
            return;
        default:
<<<<<<< HEAD
            std::cout << "Unknown error with code " << code << std::endl;
=======
            std::cout << "Unknown error with code " << code << '.' << std::endl;
>>>>>>> 206e64d2505ff996b8ccb4e2cd59fbc43533b29e

    }
}

void merrno::set_code(int new_code) {
    code = new_code;
}
