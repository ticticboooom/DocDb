//
// Created by kyle on 11/10/18.
//

#ifndef DOCDB_INDEXDOCUMENTMETADATA_H
#define DOCDB_INDEXDOCUMENTMETADATA_H

#include <string>

namespace structure{
    struct IndexDocumentMetaData{
        std::string tableName;
        std::string IndexedColumnName;
    };
}

#endif //DOCDB_INDEXDOCUMENTMETADATA_H
