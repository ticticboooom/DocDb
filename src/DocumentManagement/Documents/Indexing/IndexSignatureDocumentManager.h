//
// Created by kyle on 13/10/18.
//

#ifndef DOCDB_INDEXSIGNATUREDOCUMENTMANAGER_H
#define DOCDB_INDEXSIGNATUREDOCUMENTMANAGER_H


#include <memory>
#include "../Structure/IndexSignatureDocument.h"

class IndexSignatureDocumentManager {
public:
    void writeDocument(std::shared_ptr<structure::IndexSignatureDocument> document);
    std::shared_ptr<structure::IndexSignatureDocument> readDocument(std::shared_ptr<structure::IndexSignatureDocumentMetaData> document);
};


#endif //DOCDB_INDEXSIGNATUREDOCUMENTMANAGER_H