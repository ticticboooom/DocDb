//
// Created by Kyle on 29/09/2018.
//

#ifndef DOCDB_WSDONPARSER_H
#define DOCDB_WSDONPARSER_H


#include <string>

class WSDONParser {
public:
    static void parse(std::string documentFile);
private:
    static void parseObject(std::string object);
    static void parseArray(std::string object);
};


#endif //DOCDB_WSDONPARSER_H
