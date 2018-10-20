//
// Created by Kyle on 29/09/2018.
//

#ifndef DOCDB_WSDONPARSER_H
#define DOCDB_WSDONPARSER_H


#include <string>
#include "Structure/WSDONDocument.h"

class WSDONParser {
public:
    static structure::WSDONDocument parse(std::string str);
private:
    static std::shared_ptr<structure::WSDONObject> parseObject(std::shared_ptr<std::vector<std::string>> lines);
    static std::shared_ptr<structure::WSDONObject::array_type> parseArray(std::shared_ptr<std::vector<std::string>> lines);
    static unsigned int getEndOfObject(std::shared_ptr<std::vector<std::string>> lines, unsigned int currentIndex, unsigned int tabCount);
    static std::string cleanLine(std::string line);
    static unsigned int getTabIndex(std::string line);
};


#endif //DOCDB_WSDONPARSER_H
