// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>

#include "dirent.h"
#include "helpers.h"


std::vector<std::string> list_current_dir(const std::string &path, const std::string &wild_path) {
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> files{};
    if ((dir = opendir((path + wild_path).c_str())) != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            files.emplace_back(wild_path + ent->d_name);
        }
        closedir(dir);
    } else {
        throw std::runtime_error("Can not access the directory");
    }

    return files;
}