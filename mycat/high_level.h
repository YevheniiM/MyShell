//
// Created by yevhenii on 08.10.19.
//

#ifndef _1_MYCAT_HIGH_LEVEL_H
#define _1_MYCAT_HIGH_LEVEL_H

#include <string>

std::string read_file(int fd);
int open_file(const char* name);
void write_from_string(const std::string& content, int descriptor, bool convert_to_hex);
int close_file(int fd);

#endif //_1_MYCAT_HIGH_LEVEL_H
