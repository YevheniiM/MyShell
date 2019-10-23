//
// Created by vorumbo on 21.10.19.
//

#include <wait.h>
#include <iostream>
#include <unistd.h>

#include "my_programs.h"

void run_my_programs(std::vector<std::string> &args, const VariablesManager &variablesManager) {
    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Failed to fork()" << std::endl;
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // We are parent process
        int status;
        waitpid(pid, &status, 0);
    } else {
        // We are the child
        // Add dot to PATH
        std::string victim_name(args[0]);
        //! Вважаємо, що кількість аргументів на момент компіляції не відома!
        //! Така ситуація буде виникати у нас часто, насправді.
        //! Інакше немає потреби так складно робити.

        auto path_ptr = getenv("PATH");
        std::string path_var;
        if (path_ptr != nullptr)
            path_var = path_ptr;
        path_var += ":";
        path_var.insert(path_var.size(), variablesManager.getAllGlobalVariable());
        path_var += ":.";
        setenv("PATH", path_var.c_str(), 1);
        //! Environment is ready
        //! Prepare args array in form suitable for execvp
        std::vector<const char *> arg_for_c;
        arg_for_c.reserve(args.size());
        for (const auto &s: args)
            arg_for_c.push_back(s.c_str());
        arg_for_c.push_back(nullptr);
        //! const_cast використано, так як не бачу іншого способу
        //! з const char** отримати char* const*, який хоче ф-ція
        execvp(victim_name.c_str(), const_cast<char *const *>(arg_for_c.data()));
        exit(EXIT_FAILURE);   // exec never returns
    }
}
