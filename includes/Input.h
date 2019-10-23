// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef MYSHELL_INPUT_H
#define MYSHELL_INPUT_H

#include <string>
#include <vector>
#include <readline/history.h>
#include <readline/readline.h>

#include "VariablesManager.h"

class Input {
private:
    VariablesManager &varManager;
    std::string currentPath;
    char *buf;
    char cCurrentPath[FILENAME_MAX];
public:
    Input(VariablesManager &varManager);

    std::vector<std::string> preprocessCommand();

    std::vector<std::string> getCommand();

    char *getRaw();

    std::vector<std::string> applyWildcards(const std::string &wildcard);
};

#endif //MYSHELL_INPUT_H
