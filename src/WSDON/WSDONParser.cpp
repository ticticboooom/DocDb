//
// Created by Kyle on 29/09/2018.
//

#include <algorithm>
#include <regex>
#include <lastlog.h>
#include "WSDONParser.h"
#include "WSDONUtility.h"


std::shared_ptr<structure::WSDONObject>
WSDONParser::parseObject(std::shared_ptr<std::vector<std::string>> lines) {
    auto object = std::make_shared<structure::WSDONObject>();
    auto subObject = std::make_shared<structure::WSDONObject::object_type>();
    auto currentKey = std::string();
    auto nameRegex = std::regex("(\\[(.*)\\])");
    auto arrayKeyRegex = std::regex("(\\(array\\))");
    auto noWhite = std::regex("\\s+");
    auto isLast = false;
    if (lines->size() == 1) {
        object->setBasic(WSDONUtility::WSDONUnEscape(cleanLine((*lines)[0])));
        return object;
    }
    for (auto i = 0; i < lines->size(); i++) {
        auto line = (*lines)[i];
        auto match = std::smatch();
        if (std::regex_search(line, match, noWhite)) {
            if (match[0] == line) {
                continue;
            }
        }
        if (i == lines->size() - 1) {
            isLast = true;
        }
        if (!isLast) {
            auto lastTabIndex = getTabIndex((*lines)[i]);
            auto nextLastTabIndex = getTabIndex((*lines)[i + 1]);
            std::smatch matchResult;
            if (std::regex_search(line, matchResult, nameRegex)) {
                currentKey = matchResult.str().substr(1, matchResult.length() - 2);

                if (lastTabIndex < nextLastTabIndex && std::regex_search((*lines)[i + 1
                                                                         ], matchResult, nameRegex)) {
                    auto currentObjectEnd = getEndOfObject(lines, i + 1, lastTabIndex);
                    auto subLines = std::make_shared<std::vector<std::string>>(lines->begin() + i + 1,
                                                                               lines->begin() + currentObjectEnd);

                    (*subObject)[currentKey].setObject(parseObject(subLines)->getObject());
                    i = currentObjectEnd;
                    continue;
                }
            } else {
                if (std::regex_search(line, matchResult, arrayKeyRegex)) {
                    auto currentObjectEnd = getEndOfObject(lines, i + 1, lastTabIndex + 1);
                    auto subLines = std::make_shared<std::vector<std::string>>();
                    subLines->insert(subLines->begin(), lines->begin() + i, lines->begin() + currentObjectEnd);
                    (*subObject)[currentKey].setArray(parseArray(subLines));
                    i = currentObjectEnd - 1;
                } else {
                    (*subObject)[currentKey].setBasic(WSDONUtility::WSDONUnEscape(cleanLine(line)));
                }
            }
        } else {
            (*subObject)[currentKey].setBasic(WSDONUtility::WSDONUnEscape(cleanLine(line)));
        }
    }
    object->setObject(subObject);
    return object;
}

std::shared_ptr<std::vector<structure::WSDONObject>>
WSDONParser::parseArray(std::shared_ptr<std::vector<std::string>> lines) {
    auto arr = std::make_shared<std::vector<structure::WSDONObject>>();
    for (auto i = 2; i < lines->size(); i++) {
        auto line = (*lines)[i];
        auto lastTabIndex = getTabIndex((*lines)[i]);
        auto currentObjectEnd = getEndOfObject(lines, i + 1, lastTabIndex);
        if (lastTabIndex == getTabIndex((*lines)[1])) {
            i ++;
        }

        if (currentObjectEnd == i) {
            currentObjectEnd++;
        }
        auto subLines = std::make_shared<std::vector<std::string>>(lines->begin() + i,
                                                                   lines->begin() + currentObjectEnd);
        arr->push_back(*parseObject(subLines));
        if (currentObjectEnd == lines->size() - 1) {
            break;
        }
        i = currentObjectEnd - 1;
    }
    return arr;
}

structure::WSDONDocument WSDONParser::parse(std::string str) {
    str += "\n";
    auto prevIndex = 0;
    auto index = str.find("\n");
    auto lines = std::make_shared<std::vector<std::string>>();
    lines->reserve(std::count(str.begin(), str.end(), '\n'));
    while (index != std::string::npos) {
        auto current = std::string(str.begin() + prevIndex, str.begin() + index);
        prevIndex = index + 1;
        index = str.find("\n", index + 1);
        lines->push_back(current);
    }
    auto doc = structure::WSDONDocument();
    doc.object = parseObject(lines);
    return doc;
}

unsigned int WSDONParser::getEndOfObject(std::shared_ptr<std::vector<std::string>> lines, unsigned int currentIndex,
                                         unsigned int tabCount) {
    for (auto i = currentIndex; i < lines->size(); i++) {
        auto line = (*lines)[i];
        auto currentTabCount = getTabIndex(line);
        if (currentTabCount < tabCount) {
            return i;
        }

    }
    return lines->size();
}

std::string WSDONParser::cleanLine(std::string line) {
    WSDONUtility::removeFromString(line, "\t");
    WSDONUtility::removeFromString(line, "\r");
    WSDONUtility::removeFromString(line, "\t");
    return line;
}

unsigned int WSDONParser::getTabIndex(std::string line) {
    auto index = line.find_last_of('\t');
    if (index == std::string::npos) {
        index = 0;
    } else {
        index++;
    }
    return index;
}
