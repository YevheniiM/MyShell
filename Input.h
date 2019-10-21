//
// Created by markiian on 21.10.19.
//

#ifndef MYSHELL_INPUT_H
#define MYSHELL_INPUT_H

#include <readline/history.h>
#include <readline/readline.h>
#include <string>

class Input {
private:
    std::string currentPath;
    char* buf;
    std::string lastCommand;
public:
    Input();
    std::string & get();
};

#endif //MYSHELL_INPUT_H
