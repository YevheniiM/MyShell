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
<<<<<<< HEAD

    void setGlobalVariable(const std::string &name, std::string data);

    std::string getGlobalVariable(const std::string &name);

    std::string getAllGlobalVariable() const;

    void setLocalVariable(const std::string &name, std::string data);

    std::string getLocalVariable(const std::string &name);

    std::string getAllLocalVariable() const;
=======
    void setGlobalVariable(const std::string& name, std::string data);
    std::string getGlobalVariable(const std::string& name);

    void setLocalVariable(const std::string& name, std::string data);
    std::string getLocalVariable(const std::string& name);
>>>>>>> 206e64d2505ff996b8ccb4e2cd59fbc43533b29e

};

#endif //MYSHELL_VARIABLESMANAGER_H
