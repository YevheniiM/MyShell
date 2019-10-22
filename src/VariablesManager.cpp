//
// Created by markiian on 21.10.19.
//

#include "VariablesManager.h"

void VariablesManager::setGlobalVariable(std::string name, std::string data) {
    if ((data[0] == '\'' && data[data.size()-1]== '\'') || (data[0] == '"' && data[data.size()-1]== '"')) {
        localVariables[name] = data.substr(1, data.size()-2);
        globalVariables[name] = data.substr(1, data.size()-2);
    } else {
        localVariables[name] = data;
        globalVariables[name] = data;
    }
}

std::string VariablesManager::getGlobalVariable(std::string name) {
    return globalVariables[name];
}

void VariablesManager::setLocalVariable(std::string name, std::string data) {
    if ((data[0] == '\'' && data[data.size()-1]== '\'') || (data[0] == '"' && data[data.size()-1]== '"')) {
        localVariables[name] = data.substr(1, data.size()-2);
    } else {
        localVariables[name] = data;
    }

}

std::string VariablesManager::getLocalVariable(std::string name) {
    return localVariables[name];
}
