//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_DOCUMENTUTILITY_H
#define DOCDB_DOCUMENTUTILITY_H


#include <string>
#include "../Structure/DataDocument.h"
#include "../Structure/DocumentMetaData.h"

class DocumentUtility {
public:

    static void initialise();
    static std::string generatePath(std::shared_ptr<structure::DataDocument> doc);
    static std::string generatePath(std::shared_ptr<structure::DocumentMetaData> doc);
    static std::shared_ptr<structure::WSDONDocument>  readParseDocument(std::string path);
private:
    static std::string getSegment(std::string segment);
    static std::string rootDirectory;
    static std::string tableDirectory;
    static std::string fileExtension;
};


#endif //DOCDB_DOCUMENTUTILITY_H
