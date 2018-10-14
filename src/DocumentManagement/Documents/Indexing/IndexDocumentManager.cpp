//
// Created by kyle on 11/10/18.
//

#include "IndexDocumentManager.h"
#include "../../../WSDON/WSDONSerializer.h"
#include "../../../IO/FileWriter.h"
#include "../../../WSDON/Utility/WSDONConverters.h"
#include "../../../IO/CommonUtility/PathUtility.h"

void IndexDocumentManager::writeDocument(std::shared_ptr<structure::IndexDocument> indexDocument) {
    auto path = PathUtility::generateIndexPath(indexDocument);

    auto wsdonDocument = createWSDONDocumentFromIndexDocument(indexDocument);
    PathUtility::writeSerializeDocument(wsdonDocument, path);
}

std::shared_ptr<structure::IndexDocument>
IndexDocumentManager::readIndices(std::shared_ptr<structure::IndexDocumentMetaData> indexDocumentMetaData) {
    auto path = PathUtility::generateIndexPath(indexDocumentMetaData);

    auto wsdonDocument = PathUtility::readParseDocument(path);
    auto indexDocument = createIndexDocumentFromWSDONDocument(wsdonDocument);
    return indexDocument;
}

std::shared_ptr<structure::WSDONDocument>
IndexDocumentManager::createWSDONDocumentFromIndexDocument(std::shared_ptr<structure::IndexDocument> document) {
    auto wsdonDocument = std::make_shared<structure::WSDONDocument>();
    wsdonDocument->object = WSDONConverters::ToWSDONObject(document);
    return wsdonDocument;
}

std::shared_ptr<structure::IndexDocument>
IndexDocumentManager::createIndexDocumentFromWSDONDocument(std::shared_ptr<structure::WSDONDocument> wsdonDocument) {
    return WSDONConverters::ToIndexDocument(wsdonDocument->object);
}

