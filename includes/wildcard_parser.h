//
// Created by yevhenii on 21.10.19.
//

#ifndef MYSHELL_WILDCARD_PARSER_H
#define MYSHELL_WILDCARD_PARSER_H

#include <string>
#include <vector>

std::string convert_pattern(const std::string& pattern);
std::vector<std::string> get_matches(const std::vector<std::string>& files, const std::string& pattern);


#endif //MYSHELL_WILDCARD_PARSER_H
