//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_DOCUMENTUTILITY_H
#define DOCDB_DOCUMENTUTILITY_H


#include <string>
#include "../Structure/DataDocument.h"
#include "../Structure/DocumentMetaData.h"
#include "../Structure/IndexDocument.h"
#include "../Structure/IndexDocumentMetaData.h"

class DocumentUtility {
public:

    static void initialise();

    static std::string generatePath(std::shared_ptr<structure::DataDocument> doc);

    static std::string generatePath(std::shared_ptr<structure::DocumentMetaData> doc);

    static std::shared_ptr<structure::WSDONDocument> readParseDocument(std::string path);

    static void writeSerializeDocument(std::shared_ptr<structure::WSDONDocument> doc, std::string path);

    static std::string generateIndexPath(std::shared_ptr<structure::IndexDocumentMetaData> doc);

private:
    static std::string generateBasePath();

    static std::string getSegment(std::string segment);

    static std::string rootDirectory;
    static std::string tableDirectory;
    static std::string fileExtension;
    static std::string indexDirectory;
    static std::string indexPrefix;
};


#endif //DOCDB_DOCUMENTUTILITY_H
