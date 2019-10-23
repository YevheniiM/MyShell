// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>

#include "my_io.h"

static const char *optString = "Ah";
static const struct option longOpts[] = {
        {"help", no_argument, NULL, 'h'},
        {"A",    no_argument, NULL, 'A'},
        {NULL,   no_argument, NULL, 0}
};


static const size_t BUF_SIZE = 8192;


int main(int argc, char *argv[]) {
//    const char txt[] = {6,'a', 'b', 17, 'd', 'e', 7};
//    write_to_hex_extended(STDOUT_FILENO, txt, 0, NULL);
//    return 1;
    char buf[BUF_SIZE];
    int status = 0;

    int longIndex = 0;
    char *filename;

    int index;
    int opt;
    int hex_flag = 0;

    while ((opt = getopt_long(argc, argv, optString, longOpts, &longIndex)) != -1)
        switch (opt) {
            case 'h':
                print_msg("My analog of cat\nmycat [-h|--help] [-A] <file1> <file2> ... <fileN>\n");
                return 0;
            case 'A':
                hex_flag = 1;
                break;
            default:
                print_msg("Error occured during args parsing, consider running \"./mycat --help\"\n");
                return 1;
        }

    if (optind == argc) {
        my_print(1, "Too few arguments, consider running \"./mycat --help\"\n");
    }

    int *fd_array = malloc((argc - optind) * sizeof(int));
    for (index = optind; index < argc; index++) {
        filename = argv[index];
        int fd = open(filename, O_RDONLY);
        if (fd == -1) {
            my_print(5, "\"", filename, "\": File opening error: ", strerror(errno), "\n");
            return 1;
        }
        fd_array[index - optind] = fd;
    }


    for (int i = 0; i < (index - optind); ++i) {
        int read_buf_size = read_from(fd_array[i], buf, BUF_SIZE, &status);
        int write_res = 0;
        while (read_buf_size > 0) {
            if (hex_flag) {
                write_res = write_to_hex_extended(STDOUT_FILENO, buf, read_buf_size, &status);
            } else {
                write_res = write_to(STDOUT_FILENO, buf, read_buf_size, &status);
            }
            if (write_res == -1) {
                my_print(5, "\"", argv[optind + i], "\" Error occurred during write: ", strerror(status), "\n");
                return 1;
            }
            read_buf_size = read_from(fd_array[i], buf, BUF_SIZE, &status);
        }
        if (read_buf_size == -1) {
            my_print(5, "\"", argv[optind + i], "\" Error occurred during read: ", strerror(status), "\n");
            return 1;
        }

        close(fd_array[i]);
    }

    free(fd_array);
    return 0;


}
