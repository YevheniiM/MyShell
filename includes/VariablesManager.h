// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef MYSHELL_VARIABLESMANAGER_H
#define MYSHELL_VARIABLESMANAGER_H

#include <string>
#include <map>

class VariablesManager {
private:
    std::map<std::string, std::string> localVariables;
    std::map<std::string, std::string> globalVariables;
public:
    VariablesManager() = default;

    void setGlobalVariable(const std::string &name, std::string data);

    std::string getGlobalVariable(const std::string &name);

    std::string getAllGlobalVariable() const;

    void setLocalVariable(const std::string &name, std::string data);

    std::string getLocalVariable(const std::string &name);

    std::string getAllLocalVariable() const;

};

#endif //MYSHELL_VARIABLESMANAGER_H
