//
// Created by markiian on 21.10.19.
//

#ifndef MYSHELL_INPUT_H
#define MYSHELL_INPUT_H

#include <readline/history.h>
#include <readline/readline.h>
#include <string>
#include <vector>
#include "VariablesManager.h"

class Input {
private:
    VariablesManager & varManager;
    std::string currentPath;
    char *buf;
    char cCurrentPath[FILENAME_MAX];
public:
    Input(VariablesManager & varManager);
    std::vector<std::string> preprocessCommand();
    std::vector<std::string> getCommand();
    char* getRaw();

    std::vector<std::string> applyWildcards(const std::string &wildcard);
};

#endif //MYSHELL_INPUT_H
