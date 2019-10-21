#include <cstdio>
#include <iostream>

#include "../includes/Input.h"


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

int main(int argc, char** argv) {
    printf("Welcome! You can exit by pressing Ctrl+C at any time...\n");
    Input inp;
    while (true) {

        std::cout << inp.get() << "|" << std::endl;
    }
    return 0;
}

#pragma clang diagnostic pop