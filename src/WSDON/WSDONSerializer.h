//
// Created by Kyle on 29/09/2018.
//

#ifndef DOCDB_WSDONSERIALIZER_H
#define DOCDB_WSDONSERIALIZER_H


#include <string>
#include <memory>
#include <map>
#include "Structure/WSDONDocument.h"
#include "Structure/WSDONObject.h"

class WSDONSerializer {
public:
    static std::string serialize(std::shared_ptr<structure::WSDONDocument> doc);
private:
    static std::string serializeObject(structure::WSDONObject object, unsigned int objectDepth, bool toIndentObject);
    static std::string serializeSubObject(std::shared_ptr<structure::WSDONObject::object_type> object, unsigned int objectDepth);
    static std::string serializeArray(std::shared_ptr<std::vector<structure::WSDONObject>> array, unsigned int objectDepth);
    static std::string getIndentation(unsigned int count);
    static std::string getTitle(std::string name);
};


#endif //DOCDB_WSDONSERIALIZER_H
