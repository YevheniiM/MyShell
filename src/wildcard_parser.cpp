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


int find_last_index(const std::string& str, char x)
{
    for (size_t i = str.length() - 1; i >= 0; i--)
        if (str[i] == x)
            return i;

    return -1;
}


int is_wildcard(const std::string &command) {
    auto ind = find_last_index(command, '/');
    auto last = command;
    if (ind != -1)
        last = command.substr(ind);
    std::cout << "--- " << last << '\n';
    size_t stars = std::count(last.begin(), last.end(), '*');
    size_t open_brackets = std::count(last.begin(), last.end(), '[');
    size_t close_brackets = std::count(last.begin(), last.end(), ']');
    size_t question_mark = std::count(last.begin(), last.end(), '?');

    if (open_brackets == close_brackets && open_brackets != 0) return 0;
    if (stars) return 0;
    if (question_mark) return 0;

    if (open_brackets != close_brackets)
        throw std::invalid_argument("The syntax problem in a wildcard was detected.");

    return -1;
}