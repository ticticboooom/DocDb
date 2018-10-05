//
// Created by Kyle on 29/09/2018.
//

#include <regex>
#include "WSDONUtility.h"

std::string WSDONUtility::WSDONEscape(std::string str) {
    auto re = std::regex("(\n)|(\t)");
    std::smatch matchResult;
    if (!std::regex_search(str, matchResult, re)){
        return str;
    }
    for (auto i = 0; i < matchResult.size(); i++) {
        auto matchString = matchResult[i].str();
        if (matchString == "") {
            continue;
        }
        if (matchString == "\n") {
            str = EscapeString(str, "\n", "\\n");
        } else if (matchString == "\t") {
            str = EscapeString(str, "\t", "\\t");
        }
    }
    return str;
}

std::string WSDONUtility::WSDONUnEscape(std::string str) {
    auto re = std::regex("(\\\\n)|(\\\\t)");
    std::smatch matchResult;
    if (!std::regex_search(str, matchResult, re)){
        return str;
    }
    for (auto i = 0; i < matchResult.size(); i++) {
        auto matchString = matchResult[i].str();
        if (matchString == "") {
            continue;
        }
        if (matchString == "\\n") {
            str = EscapeString(str, "\\n", "\n");
        } else if (matchString == "\\t") {
            str = EscapeString(str, "\\t", "\t");
        }
    }
    return str;
}

std::string WSDONUtility::EscapeString(std::string value, std::string matcher, std::string replacement) {
    const auto index = value.find_first_of(matcher);
    if (index >= value.length() || index < 0) {
        return value;
    }
    value.erase(index, matcher.length());
    value.insert(index, replacement);
    return value;
}
