//
// Created by Kyle on 30/09/2018.
//

#include "DataDocumentManager.h"
#include "../CommonUtility/DocumentUtility.h"
#include "../../../IO/FileWriter.h"
#include "../../../WSDON/WSDONSerializer.h"
#include "../../../IO/FileReader.h"
#include "../../../WSDON/WSDONParser.h"

void DataDocumentManager::writeDocument(std::shared_ptr<structure::DataDocument> document) {
    auto path = DocumentUtility::generatePath(document);

    auto fw = std::make_shared<FileWriter>(path);
    auto str = WSDONSerializer::serialize(document->documentData);
    fw->writeString(str);


}

std::shared_ptr<structure::DataDocument> DataDocumentManager::readDocument(std::shared_ptr<structure::DocumentMetaData> metaData) {
    auto path = DocumentUtility::generatePath(metaData);
    auto object = DocumentUtility::readParseDocument(path);

    auto document = std::make_shared<structure::DataDocument>();
    document->documentData = *object;
    document->primaryIndexValue = metaData->primaryIndexValue;
    document->tableIdentifier  = metaData->tableIdentifier;
    return document;
}
