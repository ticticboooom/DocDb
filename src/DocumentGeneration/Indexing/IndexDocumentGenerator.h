//
// Created by kyle on 13/10/18.
//

#ifndef DOCDB_INDEXDOCUMENTGENERATOR_H
#define DOCDB_INDEXDOCUMENTGENERATOR_H


#include "../../DocumentManagement/Documents/Structure/IndexDocument.h"
#include "../../DocumentManagement/Documents/Structure/DataDocument.h"
#include "../../DocumentManagement/Documents/Structure/IndexSignatureDocument.h"
#include "../../DocumentManagement/Documents/Indexing/IndexSignatureDocumentManager.h"

class IndexDocumentGenerator {
public:
    IndexDocumentGenerator();
    std::shared_ptr<structure::IndexDocumentEntry>
    generateIndexDocumentEntry(std::shared_ptr<structure::DataDocument> doc, std::string indexColumnPath);

private:
    static std::string FindByColumnIdentifier(std::shared_ptr<structure::WSDONObject> object, std::string path);
    std::shared_ptr<IndexSignatureDocumentManager> signatureManager;
};


#endif //DOCDB_INDEXDOCUMENTGENERATOR_H
