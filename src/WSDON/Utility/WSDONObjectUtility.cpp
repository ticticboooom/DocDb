//
// Created by kyle on 13/10/18.
//

#include "WSDONObjectUtility.h"

std::shared_ptr<structure::WSDONObject>
WSDON::WSDONFindObject(std::shared_ptr<structure::WSDONObject> root, std::string path) {
    if (root.get() == nullptr) {
        return root;
    }
    auto objType = root->getType();
    if (objType == structure::WSDONObject::Array) {
        auto index = std::stoi(path);
        if (std::to_string(index) == path) {
            return WSDON::WSDONFindInArray(root->getArray(), index);
        }
    } else if (objType == structure::WSDONObject::Object) {
        auto firstKey = path;
        auto object = root->getObject();
        auto firstKeyEndIndex = path.find(':');
        if (firstKeyEndIndex != std::string::npos) {
            firstKey = std::string(path.begin(), path.begin() + firstKeyEndIndex);
            auto pObject = std::make_shared<structure::WSDONObject>((*object)[firstKey]);
            return WSDON::WSDONFindObject(pObject, path.substr(firstKeyEndIndex + 1, path.length() - 1));
        }
        return std::make_shared<structure::WSDONObject>((*object)[firstKey]);
    } else if (objType == structure::WSDONObject::Basic) {
        return root;
    }
}

std::shared_ptr<structure::WSDONObject> WSDON::WSDONFindInArray(
        std::shared_ptr<std::vector<structure::WSDONObject>> root, unsigned int index) {
    if (index > root->size() - 1) {
        return nullptr;
    }
    return std::make_shared<structure::WSDONObject>(root->at(index));
}