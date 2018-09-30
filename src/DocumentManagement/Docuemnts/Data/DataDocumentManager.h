//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_DATADOCUMENTMANAGER_H
#define DOCDB_DATADOCUMENTMANAGER_H


#include "../Structure/DataDocument.h"

class DataDocumentManager {
public:
    DataDocumentManager();
    ~DataDocumentManager();

    void writeDocument(std::shared_ptr<structure::DataDocument> document);
};


#endif //DOCDB_DATADOCUMENTMANAGER_H
