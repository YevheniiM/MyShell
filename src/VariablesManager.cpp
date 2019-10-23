//
// Created by markiian on 21.10.19.
//

#include "VariablesManager.h"

void VariablesManager::setGlobalVariable(const std::string& name, std::string data) {
    if ((data[0] == '\'' && data[data.size()-1]== '\'') || (data[0] == '"' && data[data.size()-1]== '"')) {
        localVariables[name] = data.substr(1, data.size()-2);
        globalVariables[name] = data.substr(1, data.size()-2);
    } else {
        localVariables[name] = data;
        globalVariables[name] = data;
    }
}

std::string VariablesManager::getGlobalVariable(const std::string& name) {
    return globalVariables[name];
}

void VariablesManager::setLocalVariable(const std::string& name, std::string data) {
    if ((data[0] == '\'' && data[data.size()-1]== '\'') || (data[0] == '"' && data[data.size()-1]== '"')) {
        localVariables[name] = data.substr(1, data.size()-2);
    } else {
        localVariables[name] = data;
    }

}

std::string VariablesManager::getLocalVariable(const std::string& name) {
    return localVariables[name];
}
