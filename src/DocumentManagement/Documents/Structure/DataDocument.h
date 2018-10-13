//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_DATADOCUMENT_H
#define DOCDB_DATADOCUMENT_H

#include <string>
#include "../../../WSDON/Structure/WSDONDocument.h"

namespace structure{
    struct DataDocument{
        std::string tableIdentifier;
        std::string primaryIndexIdentifier;
        std::string primaryIndexValue;
        std::shared_ptr<structure::WSDONDocument> documentData;
    };
}
#endif //DOCDB_DATADOCUMENT_H
