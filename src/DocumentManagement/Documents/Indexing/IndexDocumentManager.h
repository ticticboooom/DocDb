//
// Created by kyle on 11/10/18.
//

#ifndef DOCDB_INDEXDOCUMENTMANAGER_H
#define DOCDB_INDEXDOCUMENTMANAGER_H


#include "../Structure/IndexDocument.h"
#include "../Structure/IndexDocumentMetaData.h"
#include "../../../WSDON/Structure/WSDONDocument.h"
#include "../../../Tables/Structure/TableInitData.h"

class IndexDocumentManager {
public:
    void writeDocument(std::shared_ptr<structure::IndexDocument> indexDocument);
    std::shared_ptr<structure::IndexDocument> readIndices(std::shared_ptr<structure::IndexDocumentMetaData> indexDocumentMetaData);
private:
    std::shared_ptr<structure::WSDONDocument> createWSDONDocumentFromIndexDocument(std::shared_ptr<structure::IndexDocument> document);
    std::shared_ptr<structure::IndexDocument> createIndexDocumentFromWSDONDocument(std::shared_ptr<structure::WSDONDocument> wsdonDocument);
};


#endif //DOCDB_INDEXDOCUMENTMANAGER_H
