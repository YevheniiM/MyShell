// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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
            std::cout << "Code : " << my_errno.get_code() << " . Errno code: " << my_errno.get_errno_code() << "."
                      << std::endl;
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
    try {
        std::cout << "mpwd [-h|--help]"
                     "  Print the name of the current working directory.\n"
                     "    \n"
                     "    Exit Status:\n"
                     "    Returns 0 unless an invalid option is given or the current directory\n"
                     "    cannot be read.";
        my_errno.set_code(0, 0);
    } catch (...) {
        my_errno.set_code(-2, errno);
    }
}

void mpwd() {
    std::string directory = get_current_directory();
    if (my_errno.get_code() == 0) {
        try {
            std::cout << directory;
        } catch (...) {
            my_errno.set_code(-2, errno);
        }
    }
}

void mcd_help() {
    try {
        std::cout << "  mcd <path> [-h|--help]"
                     "  Change the shell working directory.\n"
                     "      \n"
                     "      Change the current directory to DIR";
        my_errno.set_code(0, 0);
    } catch (...) {
        my_errno.set_code(-1, errno);
    }
}

void mcd(const std::string &new_path) {
    int ret = chdir(new_path.c_str());
    if (ret == -1) my_errno.set_code(-1, errno);
    else my_errno.set_code(0, 0);
}

void mexit_help() {
    try {
        std::cout << "exit: exit [n]\n"
                     "    Exit the shell.\n"
                     "    \n"
                     "    Exits the shell with a status of N.  If N is omitted, the exit status\n"
                     "    is that of the last command executed.";
        my_errno.set_code(0, 0);
    } catch (...) {
        my_errno.set_code(-3, errno);
    }
}

void mexit(int status) {
    try {
        my_errno.set_code(0, 0);
        _exit(status);
    } catch (...) {
        my_errno.set_code(-3, errno);
    }
}

void mecho_help() {
    try {
        std::cout << "Prints the line of text.";
        my_errno.set_code(0, 0);
    } catch (...) {
        my_errno.set_code(-4, errno);
    }
}

void mecho(const std::vector<std::string> &args) {
    try {
        for (auto &arg:args) {
            std::cout << arg << " ";
        }
    } catch (...) {
        my_errno.set_code(-4, errno);
    }
}

void mexport_help() {
    try {
        std::cout << " Set export attribute for shell variables." << std::endl;
    } catch (...) {
        my_errno.set_code(-5, errno);
    }
}

void mexport(const std::vector<std::string> &args, VariablesManager &variablesManager) {
    try {
        for (auto &arg:args) {
            auto delimiterPos = arg.find('=');
            variablesManager.setLocalVariable(arg.substr(0, delimiterPos), arg.substr((delimiterPos + 1)));
            variablesManager.setGlobalVariable(arg.substr(0, delimiterPos), arg.substr((delimiterPos + 1)));
        }
    } catch (...) {
        my_errno.set_code(-5, errno);
    }
}

std::string get_current_directory() {
    try {
        char current_dir[4096];

        char *res = getcwd(current_dir, 4096);

        if (res == nullptr) my_errno.set_code(-2, errno);
        else my_errno.set_code(0, 0);
        return std::string(current_dir);
    } catch (...) {
        my_errno.set_code(-2, errno);
        return "";
    }
}