//
// Created by markiian on 21.10.19.
//

#ifndef MYSHELL_VARIABLESMANAGER_H
#define MYSHELL_VARIABLESMANAGER_H

#include <string>

class VariablesManager {
private:

public:
    VariablesManager() = default;
    void setVariable(std::string name, std::string data);
    std::string getVariable(std::string name);

};

#endif //MYSHELL_VARIABLESMANAGER_H
