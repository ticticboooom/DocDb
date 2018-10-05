//
// Created by Kyle on 29/09/2018.
//

#ifndef DOCDB_WSDONUTILITY_H
#define DOCDB_WSDONUTILITY_H


#include <string>

class WSDONUtility {
public:
    static std::string WSDONEscape(std::string str);
    static std::string WSDONUnEscape(std::string str);
private:
    static std::string EscapeString(std::string value, std::string matcher, std::string replacement);
};


#endif //DOCDB_WSDONUTILITY_H
