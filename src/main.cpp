#include <stdio.h>
#include <iostream>

#include "../includes/Input.h"


int main(int argc, char** argv) {
    printf("Welcome! You can exit by pressing Ctrl+C at any time...\n");
    Input inp;
    while (true) {

        std::cout << inp.get() << "|" << std::endl;
    }
    return 0;
}