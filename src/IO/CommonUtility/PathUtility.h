//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_DOCUMENTUTILITY_H
#define DOCDB_DOCUMENTUTILITY_H


#include <string>
#include "../../DocumentManagement/Documents/Structure/DataDocument.h"
#include "../../DocumentManagement/Documents/Structure/DocumentMetaData.h"
#include "../../DocumentManagement/Documents/Structure/IndexDocument.h"
#include "../../DocumentManagement/Documents/Structure/IndexDocumentMetaData.h"
#include "../../DocumentManagement/Documents/Structure/IndexSignatureDocument.h"
#include "../../DocumentManagement/Documents/Structure/IndexSignatureDocument.h"
#include "../../Tables/Structure/TableInitData.h"

class PathUtility {
public:

    static void initialise();

    static std::string generatePath(std::shared_ptr<structure::DataDocument> doc);

    static std::string generatePath(std::shared_ptr<structure::DocumentMetaData> doc);
    static std::string generatePath(std::shared_ptr<structure::IndexSignatureDocumentMetaData> doc);

    static std::shared_ptr<structure::WSDONDocument> readParseDocument(std::string path);

    static void writeSerializeDocument(std::shared_ptr<structure::WSDONDocument> doc, std::string path);

    static std::string generateIndexPath(std::shared_ptr<structure::IndexDocumentMetaData> doc);
    static std::string generatePath(std::shared_ptr<structure::tables::TableInitData> data);

    static std::string generateBasePath();
    static std::string getSegment(std::string segment);

private:

    static std::string rootDirectory;
    static std::string tableDirectory;
    static std::string fileExtension;
    static std::string indexDirectory;
    static std::string indexPrefix;
    static std::string indexSignaturePrefix;
    static std::string indexSignatureDirectory;
};


#endif //DOCDB_DOCUMENTUTILITY_H
