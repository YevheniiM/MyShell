#include <cstdio>
#include <iostream>
#include <regex>

#include "Input.h"
#include "merrno.h"
#include "my_programs.h"
#include "VariablesManager.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

merrno my_errno;

int main(int argc, char **argv) {
    printf("Welcome! You can exit by pressing Ctrl+C at any time...\n");
    auto variablesManager = VariablesManager();
    Input inp{variablesManager};

    variablesManager.setGlobalVariable("PATH", "/bin/:/bin/local/");

    std::vector<std::string> my_optins{"merrno", "mpwd", "mcd", "mexit", "mecho", "mexport"};
    std::vector<std::string> my_programs{"mycat"};

    std::regex varDeclaration(R"([a-zA-Z]+=.+)");
    std::regex extCommand(R"(^(.\/|..\/|\/).+)");

    while (true) {

        auto res = inp.preprocessCommand();

        if (res.size() == 0) continue;

        if (res.size() == 1 && std::regex_match(res[0], varDeclaration)) {
            auto delimiterPos = res[0].find('=');
            variablesManager.setLocalVariable(res[0].substr(0, delimiterPos), res[0].substr((delimiterPos+1)));
        } else {
            if (std::regex_match(res[0], extCommand)) {
//                TODO: perform external command
                std::cout << "external" << std::endl;
            } else {
//                TODO: perform internal command or look in the path
                std::cout << "internal" << std::endl;
            }
        }

//        Just printing parsed input
        for (auto & elem: res) {
            std::cout << "[ ] " << elem << std::endl;
        }

//        if (std::find(my_optins.begin(), my_optins.end(), res[0]) != my_optins.end()){
//            run_my_options(res);
//        }else{
//            run_my_programs(res);
//        }
//
//        if(my_errno.get_code() != 0){
//            my_errno.get_description();
//        }
    }
    return 0;
}

#pragma clang diagnostic pop