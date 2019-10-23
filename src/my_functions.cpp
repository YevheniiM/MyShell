//
// Created by vorumbo on 21.10.19.
//
#include <iostream>
#include <unistd.h>

#include "merrno.h"
#include "my_functions.h"

extern merrno my_errno;

void run_my_options(std::vector<std::string> &args, VariablesManager &variablesManager) {
    bool help = false;
    for (auto &opt: args) {
        if (opt == "-h" || opt == "-help" || opt == "--help") {
            help = true;
        }
    }

    if (args[0] == "merrno") {
        if (help) {
            merrno::help();
        } else {
            std::cout << my_errno.get_code() << std::endl;
        }
    } else if (args[0] == "mpwd") {
        if (help) {
            mpwd_help();
        } else {
            mpwd();
        }
    } else if (args[0] == "mcd") {
        if (help) {
            mcd_help();
        } else {
            mcd(args[1]);
        }
    } else if (args[0] == "mexit") {
        if (help) {
            mexit_help();
        } else {
            if (args.size() == 2) {
                try {
                    mexit(stoi(args[1]));
                } catch (...) {
                    std::cerr << "Bad code of exit" << std::endl;
                    exit(-1);
                }
            } else mexit();
        }
    } else if (args[0] == "mecho") {
        if (help) {
            mecho_help();
        } else {
            args.erase(args.begin());
            mecho(args);
        }
    } else {
        if (help) {
            mexport_help();
        } else {
            args.erase(args.begin());
            mexport(args, variablesManager);
        }
    }
    if (help || (args[0] != "mcd" && args[0] != "mexit"))
        std::cout << std::endl;
}

void mpwd_help() {
    std::cout << "mpwd [-h|--help]"
                 "  Print the name of the current working directory.\n"
                 "    \n"
                 "    Exit Status:\n"
                 "    Returns 0 unless an invalid option is given or the current directory\n"
                 "    cannot be read.";
    my_errno.set_code(0, 0);
}

void mpwd() {
    std::string directory = get_current_directory();
    if (my_errno.get_code() == 0) {
        std::cout << directory;
    }
}

void mcd_help() {
    std::cout << "  mcd <path> [-h|--help]"
                 "  Change the shell working directory.\n"
                 "      \n"
                 "      Change the current directory to DIR";
    my_errno.set_code(0, 0);
}

void mcd(const std::string &new_path) {
    int ret = chdir(new_path.c_str());
    if (ret == -1) my_errno.set_code(-1, errno);
    else my_errno.set_code(0, 0);
}

void mexit_help() {
    std::cout << "exit: exit [n]\n"
                 "    Exit the shell.\n"
                 "    \n"
                 "    Exits the shell with a status of N.  If N is omitted, the exit status\n"
                 "    is that of the last command executed.";
    my_errno.set_code(0, 0);
}

void mexit(int status) {
    my_errno.set_code(0, 0);
    _exit(status);
}

void mecho_help() {
    std::cout << "Prints the line of text.";
    my_errno.set_code(0, 0);
}

void mecho(const std::vector<std::string> &args) {
    for (auto &arg:args) {
        std::cout << arg << " ";
    }
}

void mexport_help() {
    std::cout << " Set export attribute for shell variables." << std::endl;
}

void mexport(const std::vector<std::string> &args, VariablesManager &variablesManager) {
    for (auto &arg:args) {
        auto delimiterPos = arg.find('=');
        variablesManager.setLocalVariable(arg.substr(0, delimiterPos), arg.substr((delimiterPos + 1)));
        variablesManager.setGlobalVariable(arg.substr(0, delimiterPos), arg.substr((delimiterPos + 1)));
    }
}

std::string get_current_directory() {
    char current_dir[4096];

    char *res = getcwd(current_dir, 4096);

    if (res == nullptr) my_errno.set_code(-2, errno);
    else my_errno.set_code(0, 0);

    return std::string(current_dir);
}