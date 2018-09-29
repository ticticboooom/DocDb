//
// Created by Kyle on 29/09/2018.
//

#ifndef DOCDB_WSDONDOCUMENT_H
#define DOCDB_WSDONDOCUMENT_H

#include <string>
#include "WSDONObject.h"

namespace structure{
    struct WSDONDocument{
        std::string name;
        std::shared_ptr<structure::WSDONObject> object;
    };
};
#endif //DOCDB_WSDONDOCUMENT_H
