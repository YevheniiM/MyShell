// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <regex>
#include <unistd.h>

#include "Input.h"
#include "helpers.h"
#include "my_functions.h"
#include "wildcard_parser.h"

enum Status {
    OPEN_QUOTES,
    SKIP_SEQUENCE,
    NORMAL
};

Input::Input(VariablesManager &vm) : varManager(vm) {
    currentPath = getcwd(cCurrentPath, sizeof(cCurrentPath));
}

std::vector<std::string> Input::preprocessCommand() {
    auto resCommand = this->getCommand();
    std::regex varSubstitution{R"((\$[a-zA-Z]+))"};
    std::vector<std::string> res;

    for (auto &elem: resCommand) {
        std::smatch matches;
        std::string newEntry;
        if (elem.at(0) != '\'' && elem.at(elem.size() - 1) != '\'') {
            std::string newStr;
            while (std::regex_search(elem, matches, varSubstitution, std::regex_constants::match_any)) {
                newStr.append(elem.begin(), elem.begin() + matches.position(0));
                newStr.append(varManager.getLocalVariable(matches[0].str().substr(1)));
                elem = matches.suffix().str();
            }
            newStr.append(elem.begin(), elem.end());
            newEntry = newStr;
        } else {
            newEntry = elem;
        }
        if (is_wildcard(elem) == 0) {
            auto wildcardedInput = applyWildcards(elem);
            res.insert(res.end(), wildcardedInput.begin(), wildcardedInput.end());
        } else {
            res.push_back(newEntry);
        }
    }


    return res;

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
                    case '\'':
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
        throw std::invalid_argument("The syntax problem in row.");
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
    auto path = from_wildcard(wildcard, true);
    auto card = from_wildcard(wildcard, false);

    return get_matches(list_current_dir(currentPath + path), card);
}
