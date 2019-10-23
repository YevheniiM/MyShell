// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "my_io.h"
#include "stdio.h"

size_t read_from(int fd, char *buf, size_t buf_size, int *status) {
    size_t read_bytes = 0;

    while (read_bytes < buf_size) {
        size_t ret_read = read(fd, buf + read_bytes, buf_size - read_bytes);
        if (ret_read == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                *status = errno;
                return -1;
            }
        } else if (ret_read == 0) {
            break;
        } else
            read_bytes += ret_read;
    }

    return read_bytes;
}

int write_to(int fd, char *buf, size_t buf_size, int *status) {
    size_t write_bytes = 0;
    while (write_bytes < buf_size) {
        size_t ret_write = write(fd, buf + write_bytes, buf_size - write_bytes);
        if (ret_write == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                *status = errno;
                return -1;
            }
        } else if (ret_write == 0) {
            break;
        } else
            write_bytes += ret_write;
    }
    return 0;
}

int write_to_hex_extended(int fd, const char *buf, size_t buf_size, int *status) {
    char hex_chars[] = "0123456789ABCDEF";
    char *out_buf = malloc(buf_size);
    size_t out_buf_index = 0;
    int write_res = 0;
    for (size_t i = 0; i < buf_size; ++i) {
        char buf_i = buf[i];
        if ((isprint(buf[i]) || isspace(buf[i])) == 0) {
            if ((out_buf_index + 3) > (buf_size - 1)) {
                write_res = write_to(fd, out_buf, out_buf_index, status);
                out_buf_index = 0;
            }

            out_buf[out_buf_index] = '\\';
            out_buf[out_buf_index + 1] = 'x';
            out_buf[out_buf_index + 2] = hex_chars[(buf[i] & 0xF0) >> 4];
            out_buf[out_buf_index + 3] = hex_chars[(buf[i] & 0x0F) >> 0];
            out_buf_index += 3;

        } else {
            out_buf[out_buf_index] = buf[i];
        }
        out_buf_index++;
        if (out_buf_index == buf_size) {
            write_res = write_to(fd, out_buf, out_buf_index, status);
            out_buf_index = 0;
        }

        if (write_res == -1) return -1;
    }
    if (out_buf_index != 0) {
        write_res = write_to(fd, out_buf, out_buf_index, status);
        if (write_res == -1) return -1;
    }

    free(out_buf);
    return 0;
}

void print_msg(char *msg) {
    int status;
    write_to(STDOUT_FILENO, msg, strlen(msg), &status);
}

void my_print(int count, ...) {
    va_list elements;
    va_start(elements, count);
    for (int i = 0; i < count; i++)
        print_msg(va_arg(elements,
    char *));
    va_end(elements);
}