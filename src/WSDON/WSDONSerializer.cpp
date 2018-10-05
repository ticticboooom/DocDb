//
// Created by Kyle on 29/09/2018.
//

#include "WSDONSerializer.h"
#include "WSDONUtility.h"

std::string WSDONSerializer::serialize(structure::WSDONDocument doc) {
    return serializeObject(*doc.object, 0);
}

std::string WSDONSerializer::serializeObject(structure::WSDONObject object, unsigned int objectDepth) {
    std::string result;
    auto indent = std::string("");
    auto currentObject = object.getObject();
    for (auto iter = currentObject->begin(); iter != currentObject->end(); ++iter) {
        if (objectDepth != 0) {
            indent = getIndentation(objectDepth);
        }
        result += indent;
        result += getTitle(iter->first);
        indent = getIndentation(objectDepth);
        auto objectType = iter->second.getType();
        if (objectType == structure::WSDONObject::WSDONObjectType::Object) {
            result += serializeObject(iter->second, objectDepth + 1);
        } else if (objectType == structure::WSDONObject::WSDONObjectType::Array) {
            result += serializeArray(iter->second.getArray(), objectDepth + 1);
        } else if (objectType == structure::WSDONObject::WSDONObjectType::Basic) {
            result += indent;
            result += WSDONUtility::WSDONEscape(iter->second.getBasic());
        }
    }
    return result;
}

std::string WSDONSerializer::getIndentation(unsigned int count) {
    auto result = std::string("");
    result += '\n';
    for (auto i = 0; i < count; i++) {
        result += "\t";
    }
    return result;
}

std::string WSDONSerializer::getTitle(std::string name) {
    return "[" + name + "]";
}

std::string WSDONSerializer::serializeArray(std::shared_ptr<std::vector<std::string>> array, unsigned int objectDepth) {
    std::string result;
    auto indent = getIndentation(objectDepth);
    result += indent;
    result += "(array)";
    auto innerIndent = indent + '\t';
    for (const auto item : *array) {
        result += innerIndent;
        result += WSDONUtility::WSDONEscape(item);
    }
    return result;
}
