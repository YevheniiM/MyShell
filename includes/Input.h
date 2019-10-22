//
// Created by markiian on 21.10.19.
//

#ifndef MYSHELL_INPUT_H
#define MYSHELL_INPUT_H

#include <readline/history.h>
#include <readline/readline.h>
#include <string>
#include <vector>

class Input {
private:
    std::string currentPath;
    char *buf;
    char cCurrentPath[FILENAME_MAX];
public:
    Input();
    std::vector<std::string> preprocessCommand();
    std::vector<std::string> getCommand();
    char* getRaw();

    std::vector<std::string> applyWildcards(const std::string &wildcard);
};

#endif //MYSHELL_INPUT_H
