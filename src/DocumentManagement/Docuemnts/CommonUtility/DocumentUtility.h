//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_DOCUMENTUTILITY_H
#define DOCDB_DOCUMENTUTILITY_H


#include <string>
#include "../Structure/DataDocument.h"

class DocumentUtility {
public:
    static void initialise();
    static std::string generatePath(std::shared_ptr<structure::DataDocument> doc);
private:
    static std::string rootDirectory;
    static std::string tableDirectory;
};


#endif //DOCDB_DOCUMENTUTILITY_H
