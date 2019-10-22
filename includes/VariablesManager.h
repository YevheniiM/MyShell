//
// Created by markiian on 21.10.19.
//

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
    void setGlobalVariable(std::string name, std::string data);
    std::string getGlobalVariable(std::string name);

    void setLocalVariable(std::string name, std::string data);
    std::string getLocalVariable(std::string name);

};

#endif //MYSHELL_VARIABLESMANAGER_H
