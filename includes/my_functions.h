//
// Created by vorumbo on 21.10.19.
//

#ifndef MYSHELL_MY_FUNCTIONS_H
#define MYSHELL_MY_FUNCTIONS_H

#include <vector>
#include <string>

void mpwd();

void mcd_help();

void mpwd_help();

void mecho_help();

void mexit_help();

void mexit(int code = 0);

void mcd(const std::string &new_path);

void mecho(const std::vector<std::string> &args);

void run_my_options(std::vector<std::string> &args);

#endif //MYSHELL_MY_FUNCTIONS_H
