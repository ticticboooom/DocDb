//
// Created by Kyle on 29/09/2018.
//

#include "WSDONSerializer.h"
#include "WSDONUtility.h"

std::string WSDONSerializer::serialize(std::shared_ptr<structure::WSDONDocument> doc) {
    return serializeSubObject(doc->object->getObject(), 0);
}

std::string WSDONSerializer::serializeObject(structure::WSDONObject object, unsigned int objectDepth, bool toIndentObject) {
    std::string result;
    auto objectType = object.getType();
    if (objectType == structure::WSDONObject::WSDONObjectType::Object) {
        result += serializeSubObject(object.getObject(), toIndentObject ? objectDepth + 1 : objectDepth);
    } else if (objectType == structure::WSDONObject::WSDONObjectType::Array) {
        result += serializeArray(object.getArray(), objectDepth + 1);
    } else if (objectType == structure::WSDONObject::WSDONObjectType::Basic) {
        auto indent = getIndentation(toIndentObject ? objectDepth + 1 : objectDepth);
        result += indent;
        result += WSDONUtility::WSDONEscape(object.getBasic());
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
WSDONSerializer::serializeArray(std::shared_ptr<std::vector<structure::WSDONObject>> array, unsigned int objectDepth) {
    std::string result;
    auto indent = getIndentation(objectDepth);
    result += indent;
    result += "(array)";
    for (const auto &item : *array) {
        result += serializeObject(item, objectDepth + 1, false);
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
