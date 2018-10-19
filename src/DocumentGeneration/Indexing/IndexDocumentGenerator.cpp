//
// Created by kyle on 13/10/18.
//

#include "IndexDocumentGenerator.h"
#include "../../WSDON/Utility/WSDONObjectUtility.h"


std::shared_ptr<structure::IndexDocumentEntry>
IndexDocumentGenerator::generateIndexDocumentEntry(std::shared_ptr<structure::DataDocument> doc, std::string indexColumnPath) {
    auto sigDocMeta = std::make_shared<structure::IndexSignatureDocumentMetaData>();
    sigDocMeta->tableName = doc->tableIdentifier;
    auto sigDoc = signatureManager->readDocument(sigDocMeta);
    for (const auto& item : sigDoc->indexSignatures){
        if (item.indexColumnPath == indexColumnPath){
            auto indexEntry = std::make_unique<structure::IndexDocumentEntry>();
            indexEntry->indexColumnName = item.indexColumnName;
            indexEntry->indexColumnValue = FindByColumnIdentifier(doc->documentData->object, item.indexColumnPath);
            return indexEntry;
        }
    }
    return {};
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


