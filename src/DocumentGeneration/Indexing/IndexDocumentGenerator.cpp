//
// Created by kyle on 13/10/18.
//

#include "IndexDocumentGenerator.h"
#include "../../WSDON/Utility/WSDONObjectUtility.h"


std::shared_ptr<structure::IndexDocument>
IndexDocumentGenerator::generateIndexDocument(std::shared_ptr<structure::DataDocument> doc) {
    auto sigDocMeta = std::make_shared<structure::IndexSignatureDocumentMetaData>();
    sigDocMeta->tableName = doc->tableIdentifier;
    auto sigDoc = signatureManager->readDocument(sigDocMeta);
    auto indexDocument = std::make_shared<structure::IndexDocument>();
    indexDocument->indices = std::vector<structure::IndexDocumentEntry>();
    for (const auto& item : sigDoc->indexSignatures){
        auto indexEntry = std::make_unique<structure::IndexDocumentEntry>();
        indexEntry->indexColumnName = item.indexColumnName;
        indexEntry->indexColumnValue = FindByColumnIdentifier(doc->documentData->object, item.indexColumnPath);
        indexDocument->indices.push_back(*indexEntry);
    }
    indexDocument->tableName = doc->tableIdentifier;
    return indexDocument;
}

std::string
IndexDocumentGenerator::FindByColumnIdentifier(std::shared_ptr<structure::WSDONObject> object, std::string path) {
    auto result = WSDON::WSDONFindObject(object, path);
    if (result->getType() != structure::WSDONObject::Basic){
        return "";
    }
    return result->getBasic();
}

IndexDocumentGenerator::IndexDocumentGenerator():
signatureManager() {

}


