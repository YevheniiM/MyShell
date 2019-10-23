//
// Created by markiian on 21.10.19.
//

#include "VariablesManager.h"

<<<<<<< HEAD
void VariablesManager::setGlobalVariable(const std::string &name, std::string data) {
    if ((data[0] == '\'' && data[data.size() - 1] == '\'') || (data[0] == '"' && data[data.size() - 1] == '"')) {
        localVariables[name] = data.substr(1, data.size() - 2);
        globalVariables[name] = data.substr(1, data.size() - 2);
=======
void VariablesManager::setGlobalVariable(const std::string& name, std::string data) {
    if ((data[0] == '\'' && data[data.size()-1]== '\'') || (data[0] == '"' && data[data.size()-1]== '"')) {
        localVariables[name] = data.substr(1, data.size()-2);
        globalVariables[name] = data.substr(1, data.size()-2);
>>>>>>> 206e64d2505ff996b8ccb4e2cd59fbc43533b29e
    } else {
        localVariables[name] = data;
        globalVariables[name] = data;
    }
}

<<<<<<< HEAD
std::string VariablesManager::getGlobalVariable(const std::string &name) {
    return globalVariables[name];
}

void VariablesManager::setLocalVariable(const std::string &name, std::string data) {
    if ((data[0] == '\'' && data[data.size() - 1] == '\'') || (data[0] == '"' && data[data.size() - 1] == '"')) {
        localVariables[name] = data.substr(1, data.size() - 2);
=======
std::string VariablesManager::getGlobalVariable(const std::string& name) {
    return globalVariables[name];
}

void VariablesManager::setLocalVariable(const std::string& name, std::string data) {
    if ((data[0] == '\'' && data[data.size()-1]== '\'') || (data[0] == '"' && data[data.size()-1]== '"')) {
        localVariables[name] = data.substr(1, data.size()-2);
>>>>>>> 206e64d2505ff996b8ccb4e2cd59fbc43533b29e
    } else {
        localVariables[name] = data;
    }

}

<<<<<<< HEAD
std::string VariablesManager::getLocalVariable(const std::string &name) {
=======
std::string VariablesManager::getLocalVariable(const std::string& name) {
>>>>>>> 206e64d2505ff996b8ccb4e2cd59fbc43533b29e
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
