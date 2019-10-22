//
// Created by vorumbo on 21.10.19.
//

#ifndef MYSHELL_MERRNO_H
#define MYSHELL_MERRNO_H


#include <string>

class merrno {
private:
    int code;
public:
    merrno() : code{0} {};

    static void help();

    int get_code();

    void set_code(int new_code);

    void get_description();
};


#endif //MYSHELL_MERRNO_H
