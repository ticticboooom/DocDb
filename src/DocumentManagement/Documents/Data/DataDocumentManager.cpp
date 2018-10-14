//
// Created by Kyle on 30/09/2018.
//

#include "DataDocumentManager.h"
#include "../../../IO/FileWriter.h"
#include "../../../WSDON/WSDONSerializer.h"
#include "../../../IO/FileReader.h"
#include "../../../WSDON/WSDONParser.h"
#include "../Indexing/IndexDocumentManager.h"
#include "../../../DocumentGeneration/Indexing/IndexDocumentGenerator.h"
#include "../../../IO/CommonUtility/PathUtility.h"

void DataDocumentManager::writeDocument(std::shared_ptr<structure::DataDocument> document) {
    auto path = PathUtility::generatePath(document);
    auto indexManager = std::make_unique<IndexDocumentManager>();
    auto indexGenerator = std::make_unique<IndexDocumentGenerator>();
    auto indexDocument = indexGenerator->generateIndexDocument(document);
    indexManager->writeDocument(indexDocument);


    PathUtility::writeSerializeDocument(document->documentData, path);
}

std::shared_ptr<structure::DataDocument> DataDocumentManager::readDocument(std::shared_ptr<structure::DocumentMetaData> metaData) {
    auto path = PathUtility::generatePath(metaData);
    auto object = PathUtility::readParseDocument(path);

    auto document = std::make_shared<structure::DataDocument>();
    document->documentData = object;
    document->primaryIndexValue = metaData->primaryIndexValue;
    document->tableIdentifier  = metaData->tableIdentifier;
    return document;
}
