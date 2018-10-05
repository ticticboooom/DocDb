//
// Created by Kyle on 29/09/2018.
//


#include "WSDONUtility.h"

std::string WSDONUtility::WSDONEscape(std::string str) {
    auto re = std::regex("(\n)|(\t)");
    auto replacements = std::make_shared<std::vector<std::pair<std::string, std::string>>>();
    replacements->push_back(std::make_pair("\n", "\\n"));
    replacements->push_back(std::make_pair("\t", "\\t"));
    return MatchAndReplace(str, re, replacements);
}

std::string WSDONUtility::WSDONUnEscape(std::string str) {
    auto re = std::regex("(\\\\n)|(\\\\t)");
    auto replacements = std::make_shared<std::vector<std::pair<std::string, std::string>>>();
    replacements->push_back(std::make_pair("\\n", "\n"));
    replacements->push_back(std::make_pair("\\t", "\t"));
    return MatchAndReplace(str, re, replacements);
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

std::string WSDONUtility::MatchAndReplace(std::string str, std::regex re, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> replacements) {
    std::smatch matchResult;
    while (std::regex_search(str, matchResult, re)) {
        auto matchString = matchResult[0].str();
        if (matchString == "") {
            continue;
        }
        for (const auto replacement : *replacements){
            if (matchString == replacement.first) {
                str = EscapeString(str, replacement.first, replacement.second);
            }
        }
    }
    return str;
}

void WSDONUtility::removeFromString(std::string& str, std::string toRemove) {
    auto index = str.find(toRemove);
    while (index != std::string::npos) {
        str.erase(str.begin() + index);
        index = str.find(toRemove);
    }
}
