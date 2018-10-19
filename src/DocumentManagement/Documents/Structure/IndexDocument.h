//
// Created by kyle on 11/10/18.
//

#ifndef DOCDB_INDEXDOCUMENT_H
#define DOCDB_INDEXDOCUMENT_H

#include <string>
#include "../../../WSDON/Structure/WSDONObject.h"
#include "IndexDocumentMetaData.h"

namespace structure{
    struct IndexDocumentEntry{
        std::string indexColumnName;
        std::string indexColumnValue;
    };
struct IndexDocument : public structure::IndexDocumentMetaData {
        std::vector<structure::IndexDocumentEntry> indices;
    };
}

#endif //DOCDB_INDEXDOCUMENT_H
