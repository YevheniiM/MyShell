//
// Created by yevhenii on 21.10.19.
//

#include "helpers.h"
#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <dirent.h>

namespace fs = std::experimental::filesystem;


std::vector<std::string> list_current_dir(const std::string &path) {
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> files{};
    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            files.emplace_back(ent->d_name);
        }
        closedir(dir);
    } else {
        throw std::runtime_error("Can not access the directory");
    }

    return files;
}