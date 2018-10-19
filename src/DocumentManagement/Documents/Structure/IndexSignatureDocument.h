//
// Created by kyle on 13/10/18.
//

#include <string>
#include <vector>
#include "IndexSignatureDocumentMetaData.h"

#ifndef DOCDB_INDEXSIGNATUREDOCUMENT_H
#define DOCDB_INDEXSIGNATUREDOCUMENT_H

namespace structure{
    struct IndexSignature{
        std::string indexColumnName;
        std::string indexColumnPath;
    };
struct IndexSignatureDocument : public structure::IndexSignatureDocumentMetaData{
        std::vector<IndexSignature> indexSignatures;
    };
}

#endif //DOCDB_INDEXSIGNATUREDOCUMENT_H
