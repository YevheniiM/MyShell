// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef MYCAT_MY_IO_H
#define MYCAT_MY_IO_H

size_t read_from(int fd, char *buf, size_t buf_size, int *status);

int write_to(int fd, char *buf, size_t buf_size, int *status);

void print_msg(char *msg);

void my_print(int count, ...);

int write_to_hex_extended(int fd, const char *buf, size_t buf_size, int *status);

#endif //MYCAT_MY_IO_H
