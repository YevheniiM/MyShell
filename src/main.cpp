#include <cstdio>
#include <iostream>
#include <unistd.h>

#include "../includes/Input.h"
#include "../includes/wildcard_parser.h"
#include "../includes/helpers.h"


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

int main(int argc, char **argv) {
    printf("Welcome! You can exit by pressing Ctrl+C at any time...\n");
    Input inp;
    while (true) {
        auto res = inp.getCommand();

        for (const auto& i : res) {
            std::cout << "[*] " << i << std::endl;
        }
//        std::cout << inp.getCommand() << "|" << std::endl;
//        chdir("../../");
    }
    return 0;
}

#pragma clang diagnostic pop