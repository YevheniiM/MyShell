#include <functional>
#include <unistd.h>
#include <iostream>
#include <my_functions.h>

#include "Input.h"
#include "helpers.h"
#include "wildcard_parser.h"


enum Status {
    OPEN_QUOTES,
    SKIP_SEQUENCE,
    NORMAL
};

Input::Input() {

    currentPath = getcwd(cCurrentPath, sizeof(cCurrentPath));
}

std::vector<std::string> Input::preprocessCommand() {
// TODO: replace variables, replace wildcards
}

std::vector<std::string> Input::getCommand() {
    auto data = getRaw();
    std::vector<std::string> res;
    std::string currentString;
    Status status = NORMAL;
    Status prevStatus = NORMAL;
    while (*data) {
        char c = *data++;
        if (isspace(c)) {
            if (status == OPEN_QUOTES) {
                currentString += c;
            } else if (status == SKIP_SEQUENCE) {
                currentString += c;
            } else {
                if (!currentString.empty()) {
                    res.push_back(currentString);
                    currentString.clear();
                }
            }
        } else {
            if (status == SKIP_SEQUENCE) {
                currentString += c;
                status = prevStatus;
            } else {
                switch (c) {
                    case '\\':
                        prevStatus = status;
                        status = SKIP_SEQUENCE;
                        break;
                    case '"':
                        if (status == OPEN_QUOTES) {
                            currentString += c;
                            res.push_back(currentString);
                            currentString.clear();
                            status = NORMAL;
                        } else {
                            status = OPEN_QUOTES;
                            currentString += c;
                        }
                        break;
                    default:
                        currentString += c;
                        break;
                }
            }
        }
    }
    if (status == OPEN_QUOTES || status == SKIP_SEQUENCE) {
        throw;
    } else if (!currentString.empty()) {
        res.push_back(currentString);
    }
    free(buf);
    return res;
}

char *Input::getRaw() {
    mpwd();
    buf = readline((" & "));
    if (strlen(buf) > 0) {
        add_history(buf);
    }
    return buf;
}



std::vector<std::string> Input::applyWildcards(const std::string &wildcard) {
    return get_matches(list_current_dir(currentPath), wildcard);
}