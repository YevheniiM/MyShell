// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "VariablesManager.h"

void VariablesManager::setGlobalVariable(const std::string &name, std::string data) {
    if ((data[0] == '\'' && data[data.size() - 1] == '\'') || (data[0] == '"' && data[data.size() - 1] == '"')) {
        localVariables[name] = data.substr(1, data.size() - 2);
        globalVariables[name] = data.substr(1, data.size() - 2);
    } else {
        localVariables[name] = data;
        globalVariables[name] = data;
    }
}

std::string VariablesManager::getGlobalVariable(const std::string &name) {
    return globalVariables[name];
}

void VariablesManager::setLocalVariable(const std::string &name, std::string data) {
    if ((data[0] == '\'' && data[data.size() - 1] == '\'') || (data[0] == '"' && data[data.size() - 1] == '"')) {
        localVariables[name] = data.substr(1, data.size() - 2);
    } else {
        localVariables[name] = data;
    }

}

std::string VariablesManager::getLocalVariable(const std::string &name) {
    return localVariables[name];
}

std::string VariablesManager::getAllGlobalVariable() const {
    std::string str;
    for (auto &key:globalVariables) {
        str.insert(str.size(), key.second);
    }
    return str;
}

std::string VariablesManager::getAllLocalVariable() const {
    std::string str;
    for (auto &key:localVariables) {
        str.insert(str.size(), key.second);
        str.insert(str.size(), ":");
    }
    return str;
}
