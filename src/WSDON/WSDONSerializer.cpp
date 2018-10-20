//
// Created by Kyle on 29/09/2018.
//

#include "WSDONSerializer.h"
#include "WSDONUtility.h"

std::string WSDONSerializer::serialize(std::shared_ptr<structure::WSDONDocument> doc) {
    return serializeObject(doc->object, 0, false);
}

std::string WSDONSerializer::serializeObject(std::shared_ptr<structure::WSDONObject> object, unsigned int objectDepth, bool toIndentObject) {
    std::string result;
    auto objectType = object->getType();
    if (objectType == structure::WSDONObject::WSDONObjectType::Object) {
        result += serializeSubObject(object->getObject(), toIndentObject ? objectDepth + 1 : objectDepth);
    } else if (objectType == structure::WSDONObject::WSDONObjectType::Array) {
        result += serializeArray(object->getArray(), toIndentObject ? objectDepth + 1 : objectDepth);
    } else if (objectType == structure::WSDONObject::WSDONObjectType::Basic) {
        auto indent = getIndentation(toIndentObject ? objectDepth + 1 : objectDepth);
        result += indent;
        result += WSDONUtility::WSDONEscape(object->getBasic());
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

std::string
WSDONSerializer::serializeArray(std::shared_ptr<structure::WSDONObject::array_type> array, unsigned int objectDepth) {
    std::string result;
    auto indent = getIndentation(objectDepth);
    result += indent;
    result += "(array)";
    auto indexIndent = getIndentation(objectDepth  +1);
    for (auto i = 0; i < array->size(); i++) {
        result += indexIndent;
        result += getTitle(std::to_string(i));
        result += serializeObject(array->at(i), objectDepth + 2, false);
    }
    return result;
}

std::string WSDONSerializer::serializeSubObject(std::shared_ptr<structure::WSDONObject::object_type> object,
                                                unsigned int objectDepth) {
    std::string result;
    auto indent = std::string("");
    for (auto &iter : *object) {
        if (objectDepth != 0) {
            indent = getIndentation(objectDepth);
        }
        result += indent;
        result += getTitle(iter.first);
        indent = getIndentation(objectDepth);
        result += serializeObject(iter.second, objectDepth, true);
    }

    return result;
}
