//
// Created by kyle on 11/10/18.
//

#include "IndexDocumentManager.h"
#include "../CommonUtility/DocumentUtility.h"
#include "../../../WSDON/WSDONSerializer.h"
#include "../../../IO/FileWriter.h"

void IndexDocumentManager::writeDocument(std::shared_ptr<structure::IndexDocument> indexDocument) {
    auto path = DocumentUtility::generateIndexPath(indexDocument);

    auto wsdonDocument = createWSDONDocumentFromIndexDocument(indexDocument);
    DocumentUtility::writeSerializeDocument(wsdonDocument, path);
}

std::shared_ptr<structure::IndexDocument> IndexDocumentManager::readIndices(std::shared_ptr<structure::IndexDocumentMetaData> indexDocumentMetaData) {
    auto path = DocumentUtility::generateIndexPath(indexDocumentMetaData);

    auto wsdonDocument = DocumentUtility::readParseDocument(path);
    auto indexDocument =  createIndexDocumentFromWSDONDocument(wsdonDocument);
    return indexDocument;
}

std::shared_ptr<structure::WSDONDocument>
IndexDocumentManager::createWSDONDocumentFromIndexDocument(std::shared_ptr<structure::IndexDocument> document) {
    auto wsdonDocument = structure::WSDONDocument();
    auto wsdonArray = std::shared_ptr<std::vector<structure::WSDONObject>>();
    wsdonDocument.object = std::make_shared<structure::WSDONObject>();
    wsdonArray->reserve(document->indices.size());
    for (auto &index : document->indices) {
        auto object = structure::WSDONObject();
        auto map = std::shared_ptr<structure::WSDONObject::object_type>();
        (*map)["IndexColumnName"] = structure::WSDONObject();
        (*map)["IndexColumnName"].setBasic(index.indexColumnName);
        (*map)["IndexColumnValue"] = structure::WSDONObject();
        (*map)["IndexColumnValue"].setBasic(index.indexColumnValue);
        object.setObject(map);
        wsdonArray->push_back(object);
    }
    wsdonDocument.object->setArray(wsdonArray);
}

std::shared_ptr<structure::IndexDocument>
IndexDocumentManager::createIndexDocumentFromWSDONDocument(std::shared_ptr<structure::WSDONDocument> wsdonDocument) {
    auto type = wsdonDocument->object->getType();
    auto indexDocument = std::make_shared<structure::IndexDocument>();
    if (type == structure::WSDONObject::Array){
        auto array = wsdonDocument->object->getArray();
        for (auto i =0; i < array->size(); i++){
            auto currentWsdonObject = (*array)[i];
            auto indexEntry = structure::IndexDocumentEntry();
            if (currentWsdonObject.getType() == structure::WSDONObject::Object){
                auto currentItem = currentWsdonObject.getObject();
                indexEntry.indexColumnName = (*currentItem)["IndexColumnName"].getBasic();
                indexEntry.indexColumnValue = (*currentItem)["IndexColumnValue"].getBasic();
            }
            indexDocument->indices.push_back(indexEntry);
        }
    }
    return indexDocument;
}
