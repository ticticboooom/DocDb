//
// Created by Kyle on 30/09/2018.
//

#include "DataDocumentManager.h"
#include "../CommonUtility/DocumentUtility.h"
#include "../../../IO/FileWriter.h"
#include "../../../WSDON/WSDONSerializer.h"

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
