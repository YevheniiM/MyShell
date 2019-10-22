//
// Created by yevhenii on 21.10.19.
//

#include <regex>
#include <vector>
#include <iostream>

#include "wildcard_parser.h"

using std::vector;


std::string convert_pattern(const std::string &pattern) {
    std::string reg_pattern;
    for (auto s: pattern) {
        if (s == '*')
            reg_pattern += ".*";
        else if (s == '.')
            reg_pattern += "\\.";
        else if (s == '?')
            reg_pattern += '.';
        else {
            reg_pattern += s;
        }
    }
    return reg_pattern;
}


vector<std::string> get_matches(const vector<std::string> &files, const std::string &pattern) {
    vector<std::string> final{};
    std::regex rp(convert_pattern(pattern));

    for (const auto &f: files) {
        if (std::regex_match(f, rp)) {
            final.push_back(f);
        }
    }

    return final;
}


bool is_wildcard(const std::string &command) {
    size_t stars = std::count(command.begin(), command.end(), '*');
    size_t open_brackets = std::count(command.begin(), command.end(), '[');
    size_t close_brackets = std::count(command.begin(), command.end(), ']');
    size_t question_mark = std::count(command.begin(), command.end(), '?');

    if (open_brackets == close_brackets && open_brackets != 0) return true;
    if (stars) return true;
    if (question_mark) return true;

    if (open_brackets != close_brackets)
        throw std::invalid_argument("The syntax problem in a wildcard was detected.");

    return false;
}