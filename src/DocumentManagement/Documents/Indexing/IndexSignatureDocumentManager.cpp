//
// Created by kyle on 13/10/18.
//

#include "IndexSignatureDocumentManager.h"
#include "../../../WSDON/Utility/WSDONConverters.h"
#include "../../../WSDON/Structure/WSDONDocument.h"
#include "../../../IO/CommonUtility/PathUtility.h"


void IndexSignatureDocumentManager::writeDocument(std::shared_ptr<structure::IndexSignatureDocument> document) {

    auto wsdonDocument = std::make_shared<structure::WSDONDocument>();
    auto object = WSDONConverters::ToWSDONObject(document);
    wsdonDocument->object = object;

    auto path = PathUtility::generatePath(document);

    PathUtility::writeSerializeDocument(wsdonDocument, path);

}

std::shared_ptr<structure::IndexSignatureDocument> IndexSignatureDocumentManager::readDocument(std::shared_ptr<structure::IndexSignatureDocumentMetaData> document) {
    auto path = PathUtility::generatePath(document);
    auto wsdonDocument = PathUtility::readParseDocument(path);

    auto indexSignatureDocument = WSDONConverters::ToIndexSignatureDocument(wsdonDocument->object);
    return indexSignatureDocument;
}
