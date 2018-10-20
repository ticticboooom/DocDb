//
// Created by kyle on 13/10/18.
//

#ifndef DOCDB_WSDONOBJECTUTILITY_H
#define DOCDB_WSDONOBJECTUTILITY_H


#include "../Structure/WSDONObject.h"

namespace WSDON {
    std::shared_ptr<structure::WSDONObject>
    WSDONFindObject(std::shared_ptr<structure::WSDONObject> root, std::string path);

    std::shared_ptr<structure::WSDONObject>
    WSDONFindInArray(std::shared_ptr<structure::WSDONObject::array_type> root, unsigned int index);
}


#endif //DOCDB_WSDONOBJECTUTILITY_H
