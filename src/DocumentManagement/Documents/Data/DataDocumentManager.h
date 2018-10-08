//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_DATADOCUMENTMANAGER_H
#define DOCDB_DATADOCUMENTMANAGER_H


#include "../Structure/DataDocument.h"
#include "../Structure/DocumentMetaData.h"

class DataDocumentManager {
public:
    void writeDocument(std::shared_ptr<structure::DataDocument> document);
    std::shared_ptr<structure::DataDocument> readDocument(std::shared_ptr<structure::DocumentMetaData> metaData);
};


#endif //DOCDB_DATADOCUMENTMANAGER_H
