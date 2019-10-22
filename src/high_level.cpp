//
// Created by yevhenii on 08.10.19.
//

#include "high_level.h"

#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include "low_level.h"


constexpr int BUFFER_SIZE = 1024 * 1024;


std::string read_into_string(int fd) {
    std::string content;

    char buffer[BUFFER_SIZE + 1];
    int status;
    int read_whole = 0;

    do {
        read_whole = read_buffer(fd, buffer, BUFFER_SIZE, &status);
        content += std::string{buffer};
    } while (!read_whole);

    return content;
}


void write_from_string(const std::string &content, int descriptor, bool convert_to_hex) {
    int status;
    if (convert_to_hex) {
        write_hex_buffer(descriptor, content.c_str(), content.length(), &status);
    } else {
        write_buffer(descriptor, content.c_str(), content.length(), &status);
    }

    if (status != 0)
        std::cerr << "Writing to buffer finished with errno: " + std::to_string(status);
}


std::string read_file(const int fd) {
    return read_into_string(fd);
}

int open_file(const char* name){
    return _open(name, O_RDONLY);
}

int close_file(int fd){
    return  _close(fd);
}