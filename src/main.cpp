#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <algorithm>

#include "Input.h"
#include "merrno.h"
#include "my_programs.h"
#include "my_functions.h"
#include "wildcard_parser.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

merrno my_errno;

int main(int argc, char **argv) {
    printf("Welcome! You can exit by pressing Ctrl+C at any time...\n");
    Input inp;
    std::vector<std::string> my_optins{"merrno", "mpwd", "mcd", "mexit", "mecho", "mexport"};
    std::vector<std::string> my_programs{"mycat"};

    while (true) {
        auto res = inp.getCommand();

        if (std::find(my_optins.begin(), my_optins.end(), res[0]) != my_optins.end()){
            run_my_options(res);
        }else{
            run_my_programs(res);
        }

        if(my_errno.get_code() != 0){
            my_errno.get_description();
        }
    }
    return 0;
}

#pragma clang diagnostic pop