//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_DOCUMENTMETADATA_H
#define DOCDB_DOCUMENTMETADATA_H

#include <string>

namespace structure{
    struct DocumentMetaData {
    public:
        std::string tableIdentifier;
        std::string primaryIndexValue;
    };
}

#endif //DOCDB_DOCUMENTMETADATA_H
