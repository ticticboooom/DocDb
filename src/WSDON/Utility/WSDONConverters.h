//
// Created by kyle on 13/10/18.
//

#ifndef DOCDB_WSDONCONVERTERS_H
#define DOCDB_WSDONCONVERTERS_H


#include "../Structure/WSDONObject.h"
#include "../../DocumentManagement/Documents/Structure/IndexDocument.h"
#include "../../DocumentManagement/Documents/Structure/IndexSignatureDocument.h"

class WSDONConverters {
public:
    static std::shared_ptr<structure::WSDONObject> ToWSDONObject(std::shared_ptr<structure::IndexDocument> indexDocument);
    static std::shared_ptr<structure::IndexDocument> ToIndexDocument(std::shared_ptr<structure::WSDONObject> wsdonObject);
    static std::shared_ptr<structure::WSDONObject> ToWSDONObject(std::shared_ptr<structure::IndexSignatureDocument> indexDocument);
    static std::shared_ptr<structure::IndexSignatureDocument> ToIndexSignatureDocument(std::shared_ptr<structure::WSDONObject> wsdonObject);
};


#endif //DOCDB_WSDONCONVERTERS_H
