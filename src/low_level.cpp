//
// Created by yevhenii on 08.10.19.
//

#include <iostream>
#include <unistd.h>
#include <sstream>
#include <cctype>
#include <fcntl.h>


int read_buffer(int fd, char *buffer, ssize_t size, int *status) {
    ssize_t read_bytes = 0;
    while (read_bytes < size) {
        ssize_t read_now = read(fd, buffer + read_bytes, size - read_bytes);
        if (read_now == -1) {
            if (errno == EINTR)
                continue;
            else {
                *status = errno;
                return -1;
            }
        } else {
            read_bytes += read_now;
            if (read_now == 0) {
                buffer[read_bytes] = '\0';
                *status = 0;
                return 1;
            }
        }
    }
    *status = 0;
    return 0;
}

int write_buffer(int fd, const char *buffer, ssize_t size, int *status) {
    ssize_t written_bytes = 0;
    while (written_bytes < size) {
        ssize_t written_now = write(fd, buffer + written_bytes, size - written_bytes);
        if (written_now == -1) {
            if (errno == EINTR) continue;
            else {
                *status = errno;
                return -1;
            }
        } else {
            written_bytes += written_now;
        }
    }
    *status = 0;
    return 0;
}

std::string convert_to_hex_buffer(const char *buffer, ssize_t size) {
    std::stringstream ss;

    for (ssize_t i = 0; i < size; ++i) {
        if (!isprint(buffer[i]) and !isspace(buffer[i])) {
            char hex[4];
            sprintf(hex, "\\x%x", static_cast<unsigned char>(buffer[i]));
            ss << hex[0] << hex[1] << static_cast<char>(toupper(hex[2])) << static_cast<char>(toupper(hex[3]));
        } else
            ss << buffer[i];
    }
    return ss.str();
}

void write_hex_buffer(int fd, const char *buffer, ssize_t size, int *status) {
    std::string converted = convert_to_hex_buffer(buffer, size);
    write_buffer(fd, converted.c_str(), converted.length(), status);
}

int _open(const char *name, int flag) {
    int fd;
    do {
        fd = open(name, flag);
        if (fd == -1) {
            if (errno == EINTR)
                continue;
            else
                return fd;
        } else {
            return fd;
        }
    } while (true);
}

int _close(int fd) {
    int status;
    do {
        status = close(fd);
        if (status == -1) {
            if (errno == EINTR)
                continue;
            else
                return status;
        } else {
            return status;
        }
    } while (true);
};