// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <regex>
#include <iostream>

#include "Input.h"
#include "merrno.h"
#include "my_programs.h"
#include "my_functions.h"
#include "VariablesManager.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

merrno my_errno;

int main(int argc, char **argv) {
    std::cout << "Welcome! You can exit by pressing Ctrl+C at any time...\n" << std::endl;
    auto variablesManager = VariablesManager();
    Input inp{variablesManager};

    std::stringstream mstringstream;
    mstringstream << "/bin/:/bin/local/:" << get_current_directory();
    variablesManager.setGlobalVariable("PATH", mstringstream.str());

    std::vector<std::string> my_optins{"merrno", "mpwd", "mcd", "mexit", "mecho", "mexport"};
    std::vector<std::string> my_programs{"mycat"};

    std::regex varDeclaration(R"([a-zA-Z]+=.+)");
    std::regex extCommand(R"(^(.\/|..\/|\/).+)");

    while (true) {

        auto res = inp.preprocessCommand();

        if (res.empty()) continue;

        if (res.size() == 1 && std::regex_match(res[0], varDeclaration)) {
            std::cout << 1 << std::endl;
            auto delimiterPos = res[0].find('=');
            variablesManager.setLocalVariable(res[0].substr(0, delimiterPos), res[0].substr((delimiterPos + 1)));
        } else {
            if (std::find(my_optins.begin(), my_optins.end(), res[0]) != my_optins.end()) {
                run_my_options(res, variablesManager);
            } else {
                run_my_programs(res, variablesManager);
                for(auto & r: res){
                    std::cout << r << std::endl;
                }
            }
        }

        if (my_errno.get_code() != 0) {
            my_errno.get_description();
        }
    }
    return 0;
}

#pragma clang diagnostic pop