//
// Created by yevhenii on 21.10.19.
//

#include "../includes/wildcard_parser.h"

#include <iostream>
#include <vector>
#include <regex>

using std::vector;


std::string convert_pattern(const std::string& pattern){
    std::string reg_pattern;
    for(auto s: pattern){
        if(s == '*')
            reg_pattern += ".*";
        else if (s == '.')
            reg_pattern += "\\.";
        else if (s == '?')
            reg_pattern += '.';
        else{
            reg_pattern += s;
        }
    }
    return reg_pattern;
}


vector<std::string> get_matches(const vector<std::string>& files, const std::string& pattern){
    vector<std::string> final{};
    std::regex rp(convert_pattern(pattern));

    for(const auto& f: files){
        if (std::regex_match(f, rp)){
            final.push_back(f);
        }
    }

    return final;
}
