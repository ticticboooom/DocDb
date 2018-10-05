//
// Created by Kyle on 29/09/2018.
//

#ifndef DOCDB_WSDONUTILITY_H
#define DOCDB_WSDONUTILITY_H

#include <regex>
#include <string>

class WSDONUtility {
public:
    static std::string WSDONEscape(std::string str);
    static std::string WSDONUnEscape(std::string str);
    static void removeFromString(std::string& str, std::string toRemove);
private:
    static std::string EscapeString(std::string value, std::string matcher, std::string replacement);
    static std::string MatchAndReplace(std::string str, std::regex re, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> replacements);

};


#endif //DOCDB_WSDONUTILITY_H
