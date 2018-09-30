//
// Created by Kyle on 29/09/2018.
//

#include <regex>
#include "WSDONUtility.h"

std::string WSDONUtility::WSDONEscape(std::string str) {
    auto re = std::regex("(\n)|(\t)");
    std::smatch matchResult;
    std::regex_search(str, matchResult, re);
    for (const auto mat : matchResult) {
        auto matchString = mat.str();
        if (matchString == "") {
            continue;
        }
        if (matchString == "\n") {
            const auto index = str.find_first_of('\n');
            if (index > str.length() || index < 0) {
                continue;
            }
            str[index] = 'n';
            str = str.insert(index, "\\");
        } else if (matchString == "\t") {
            const auto index = str.find_first_of('\t');
            if (index > str.length() || index < 0) {
                continue;
            }
            str[index] = 't';
            str = str.insert(index, "\\");
        }
    }
    return str;
}

std::string WSDONUtility::WSDONUnEscape(std::string str) {
    auto re = std::regex("(\\n)|(\\t)");
    std::smatch matchResult;
    std::regex_search(str, matchResult, re);
    for (const auto mat : matchResult) {
        auto matchString = mat.str();
        if (matchString == "") {
            continue;
        }
        if (matchString == "\\n") {
            const auto index = str.find_first_of("\\n");
            if (index > str.length() || index < 0) {
                continue;
            }
            str[index] = '\n';
        } else if (matchString == "\t") {
            const auto index = str.find_first_of("\\t");
            if (index > str.length() || index < 0) {
                continue;
            }
            str[index] = '\t';
        }
    }
    return str;
}
