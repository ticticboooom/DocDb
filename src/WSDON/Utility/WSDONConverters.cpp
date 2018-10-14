//
// Created by kyle on 13/10/18.
//

#include "WSDONConverters.h"

std::shared_ptr<structure::WSDONObject>
WSDONConverters::ToWSDONObject(std::shared_ptr<structure::IndexDocument> indexDocument) {
    auto object = std::make_shared<structure::WSDONObject>();
    auto wsdonArray = std::make_shared<std::vector<structure::WSDONObject>>();
    if (indexDocument->indices.size() != 0){
        wsdonArray->reserve(indexDocument->indices.size());
    }
    for (auto &index : indexDocument->indices) {
        auto object = structure::WSDONObject();
        auto map = std::shared_ptr<structure::WSDONObject::object_type>();
        (*map)["IndexColumnName"] = structure::WSDONObject();
        (*map)["IndexColumnName"].setBasic(index.indexColumnName);
        (*map)["IndexColumnValue"] = structure::WSDONObject();
        (*map)["IndexColumnValue"].setBasic(index.indexColumnValue);
        object.setObject(map);
        wsdonArray->push_back(object);
    }
    object->setArray(wsdonArray);
    return object;
}

std::shared_ptr<structure::WSDONObject>
WSDONConverters::ToWSDONObject(std::shared_ptr<structure::IndexSignatureDocument> indexDocument) {
    auto object = std::make_shared<structure::WSDONObject>();
    auto map = std::make_shared<structure::WSDONObject::object_type>();
    (*map)["TableName"] = structure::WSDONObject();
    (*map)["TableName"].setBasic(indexDocument->tableName);
    auto arr = std::make_shared<std::vector<structure::WSDONObject>>();
    arr->resize(indexDocument->indexSignatures.size());
    std::fill(arr->begin(), arr->end(), structure::WSDONObject());
    for (int i = 0; i < indexDocument->indexSignatures.size(); ++i) {
        auto current = indexDocument->indexSignatures[i];
        auto currentMap = std::make_shared<structure::WSDONObject::object_type>();

        (*currentMap)["IndexColumnName"] = structure::WSDONObject();
        (*currentMap)["IndexColumnName"].setBasic(current.indexColumnName);
        (*currentMap)["IndexColumnPath"] = structure::WSDONObject();
        (*currentMap)["IndexColumnPath"].setBasic(current.indexColumnPath);


        (*arr)[i].setObject(currentMap);
    }
    (*map)["IndexSignatures"] = structure::WSDONObject();
    (*map)["IndexSignatures"].setArray(arr);
    object->setObject(map);

    return object;
}

std::shared_ptr<structure::IndexDocument>
WSDONConverters::ToIndexDocument(std::shared_ptr<structure::WSDONObject> wsdonObject) {
    auto type = wsdonObject->getType();
    auto indexDocument = std::make_shared<structure::IndexDocument>();
    if (type == structure::WSDONObject::Array) {
        auto array = wsdonObject->getArray();
        for (auto i = 0; i < array->size(); i++) {
            auto currentWsdonObject = (*array)[i];
            auto indexEntry = structure::IndexDocumentEntry();
            if (currentWsdonObject.getType() == structure::WSDONObject::Object) {
                auto currentItem = currentWsdonObject.getObject();
                indexEntry.indexColumnName = (*currentItem)["IndexColumnName"].getBasic();
                indexEntry.indexColumnValue = (*currentItem)["IndexColumnValue"].getBasic();
            }
            indexDocument->indices.push_back(indexEntry);
        }
    }
    return indexDocument;
}

std::shared_ptr<structure::IndexSignatureDocument>
WSDONConverters::ToIndexSignatureDocument(std::shared_ptr<structure::WSDONObject> wsdonObject) {
    auto type = wsdonObject->getType();
    if (type != structure::WSDONObject::Object){
        return nullptr;
    }
    auto indexSignatureDocument = std::make_shared<structure::IndexSignatureDocument>();
    auto object = wsdonObject->getObject();
    auto signatures = (*object)["IndexSignatures"];
    indexSignatureDocument->tableName = (*object)["TableName"].getBasic();
    indexSignatureDocument->indexSignatures = std::vector<structure::IndexSignature>();
    if (signatures.getType() == structure::WSDONObject::Array){
        auto arr = signatures.getArray();
        indexSignatureDocument->indexSignatures.reserve(arr->size());
        for (const auto& item : *arr){
            if (item.getType() == structure::WSDONObject::Object){
                auto currentSigObject = item.getObject();
                auto indexSignature = structure::IndexSignature();
                indexSignature.indexColumnPath = (*currentSigObject)["IndexColumnPath"].getBasic();
                indexSignature.indexColumnName = (*currentSigObject)["IndexColumnName"].getBasic();
                indexSignatureDocument->indexSignatures.push_back(indexSignature);
            }
        }
    }
    return indexSignatureDocument;
}
