#include <functional>
#include "../includes/Input.h"
#include <unistd.h>
#include <iostream>

Input::Input() {
    char cCurrentPath[FILENAME_MAX];
    currentPath = getcwd(cCurrentPath, sizeof(cCurrentPath));
}

std::string &Input::get() {
    buf = readline((currentPath + "& ").c_str());
    if (strlen(buf) > 0) {
        add_history(buf);
    }
    lastCommand = buf;
    free(buf);
    return lastCommand;
}

