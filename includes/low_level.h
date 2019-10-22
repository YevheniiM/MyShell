//
// Created by yevhenii on 08.10.19.
//

#ifndef _1_MYCAT_LOW_LEVEL_H
#define _1_MYCAT_LOW_LEVEL_H

#include <monetary.h>

int read_buffer(int fd, char *buffer, ssize_t size, int *status);
int write_buffer(int fd, const char *buffer, ssize_t size, int *status);
void write_hex_buffer(int fd, const char *buffer, ssize_t size, int *status);
int _open(const char* name, int flag);
int _close(int fd);

#endif //_1_MYCAT_LOW_LEVEL_H
