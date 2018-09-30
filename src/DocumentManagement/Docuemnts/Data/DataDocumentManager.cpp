//
// Created by Kyle on 30/09/2018.
//

#include "DataDocumentManager.h"
#include "../CommonUtility/DocumentUtility.h"
#include "../../../IO/FileWriter.h"
#include "../../../WSDON/WSDONSerializer.h"
#include "../../../IO/FileReader.h"
#include "../../../WSDON/WSDONParser.h"

DataDocumentManager::DataDocumentManager() {

}

DataDocumentManager::~DataDocumentManager() {

}

void DataDocumentManager::writeDocument(std::shared_ptr<structure::DataDocument> document) {
    auto path = DocumentUtility::generatePath(document);

    auto fw = std::make_shared<FileWriter>(path);
    auto str = WSDONSerializer::serialize(document->documentData);
    fw->writeString(str);


}

std::shared_ptr<structure::DataDocument> DataDocumentManager::readDocument(std::shared_ptr<structure::DocumentMetaData> metaData) {
    auto path = DocumentUtility::generatePath(metaData);
    auto fr = std::make_shared<FileReader>(path);
    auto contents = fr->readContents();
    auto parser = WSDONParser();
    auto object = parser.parse(contents);
    auto document = std::make_shared<structure::DataDocument>();
    document->documentData = object;
    document->primaryIndexValue = metaData->primaryIndexValue;
    document->tableIdentifier  = metaData->tableIdentifier;
    return document;
}
