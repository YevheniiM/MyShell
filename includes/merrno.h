// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef MYSHELL_MERRNO_H
#define MYSHELL_MERRNO_H


#include <string>

class merrno {
private:
    int code, errno_code;
public:
    merrno() : code{0}, errno_code{0} {};

    static void help();

    int get_code();

    int get_errno_code();

    void set_code(int new_code, int new_errno_code);

    void get_description();
};


#endif //MYSHELL_MERRNO_H
