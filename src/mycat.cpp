#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <vector>
#include <fcntl.h>
#include "high_level.h"

const char *short_options = "hA";
const option long_options[] = {
        {"help", false, nullptr, 'h'}
};

class Config {
    bool to_hex;
    std::vector<int> files;

public:
    Config() {
        files = std::vector<int>();
        to_hex = false;
    }

    std::vector<int> get_files() {
        return files;
    }

    bool is_to_hex() {
        return to_hex;
    }

    void add_file(int name) {
        files.push_back(name);
    }

    void set_to_hex(bool value) {
        to_hex = value;
    }

    void close_all() {
        for (const auto fd: files) {
            int s = close_file(fd);
            if (s == -1)
                write_from_string("Error while closing file occurred\n", 2, false);
        }
    }
};

int main(int argc, char *argv[]) {
    int opt;
    Config config;

    do {
        opt = getopt_long(argc, argv, short_options, long_options, nullptr);
        switch (opt) {
            case 'h':
                std::cout << "Usage: mycat [-h|--help] [-A] <file1> <file2> ... <fileN>" << std::endl;
                exit(0);
            case 'A':
                config.set_to_hex(true);
                break;
            default:
                break;
        }
    } while (opt != -1);

    if (optind == argc){
        write_from_string("There are no files to open\n", 2, false);
        exit(3);
    }

    for (; optind < argc; optind++) {
        int fd = open_file(argv[optind]);
        if (fd == -1){
            write_from_string("Error opening the file\n", 2, false);
            config.close_all();
            exit(1);
        }
        config.add_file(fd);
    }

    for (const auto &f: config.get_files()) {
        write_from_string(read_file(f), 1, config.is_to_hex());
    }

    config.close_all();
    return 0;
}