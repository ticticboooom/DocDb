//
// Created by kyle on 14/10/18.
//

#include "Table.h"
#include "../IO/FileSystem/CrossFileSystemUtility.h"
#include "../IO/CommonUtility/PathUtility.h"
#include "../DocumentManagement/Documents/Indexing/IndexDocumentManager.h"
#include "../DocumentManagement/Documents/Indexing/IndexSignatureDocumentManager.h"
#include "../WSDON/Utility/WSDONConverters.h"
#include "../WSDON/Structure/WSDONObjectDict.h"

void Table::init(std::shared_ptr<structure::tables::TableInitData> initData) {
    auto indexSignatureManager = std::make_unique<IndexSignatureDocumentManager>();
    auto sigDocMeta = std::make_shared<structure::IndexSignatureDocumentMetaData>();
    sigDocMeta->tableName = initData->name;
    auto indexSignature = indexSignatureManager->readDocument(sigDocMeta);
    auto indexDocumentManager = std::make_unique<IndexDocumentManager>();
    for (int i = 0; i < indexSignature->indexSignatures.size(); ++i) {
        auto indexDocumentMeta = std::make_shared<structure::IndexDocumentMetaData>();
        indexDocumentMeta->tableName = initData->name;
        indexDocumentMeta->IndexedColumnName = indexSignature->indexSignatures[i].indexColumnName;
        (*indexDocuments)[indexDocumentMeta->IndexedColumnName] = indexDocumentManager->readIndices(indexDocumentMeta);
        (*indexDocuments)[indexDocumentMeta->IndexedColumnName]->IndexedColumnName = indexDocumentMeta->IndexedColumnName;
        (*indexDocuments)[indexDocumentMeta->IndexedColumnName]->tableName = name;

    }
}

void Table::create(std::shared_ptr<structure::tables::TableCreateData> createData) {
    auto success = CrossFileSystemUtility::createDirectory(PathUtility::generatePath(createData));
    auto indexSignatureManager = std::make_unique<IndexSignatureDocumentManager>();
    auto indexDocumentManager = std::make_unique<IndexDocumentManager>();
    auto indexSignatureDocument = std::make_shared<structure::IndexSignatureDocument>();
    indexSignatureDocument->indexSignatures = std::vector<structure::IndexSignature>();
    indexSignatureDocument->tableName = createData->name;
    for (int i = 0; i < createData->indices.size(); ++i) {
        auto signature = structure::IndexSignature();
        signature.indexColumnName = createData->indices[i].columnName;
        signature.indexColumnPath = createData->indices[i].columnPath;
        indexSignatureDocument->indexSignatures.push_back(signature);

        auto indexDocument = std::make_shared<structure::IndexDocument>();
        indexDocument->indices = std::vector<structure::IndexDocumentEntry>();
        indexDocument->tableName = createData->name;
        indexDocument->IndexedColumnName = createData->indices[i].columnName;
        indexDocumentManager->writeDocument(indexDocument);
    }
    indexSignatureManager->writeDocument(indexSignatureDocument);
    init(createData);
}

Table::Table(std::shared_ptr<structure::tables::TableCreateData> createData) : name(createData->name) {
    indexDocuments = std::make_shared<std::map<std::string, std::shared_ptr<structure::IndexDocument>>>();
    dataDocumentManager = std::make_unique<DataDocumentManager>();
    if (exists(createData)) {
        init(createData);
    } else {
        create(createData);
    }
}

bool Table::exists(std::shared_ptr<structure::tables::TableCreateData> createData) {
    return CrossFileSystemUtility::directoryExists(PathUtility::generatePath(createData));
}

void Table::doStuff() {
    auto doc = std::make_shared<structure::DataDocument>();
    doc->tableIdentifier = name;
    doc->primaryIndexIdentifier = "id",
            doc->primaryIndexValue = "2";
    doc->documentData = std::make_shared<structure::WSDONDocument>();
    doc->documentData->object = std::make_shared<structure::WSDONObject>();

    auto obj = structure::WSDONObjectDict();
    obj["id"] = "2";
    obj["name"] = "hola";
    doc->documentData->object = obj.object;
    dataDocumentManager->writeDocument(doc, indexDocuments);
    writeIndexDocument("id");
    auto metaDoc = std::make_shared<structure::DocumentMetaData>();
    metaDoc->tableIdentifier = name;
    metaDoc->primaryIndexValue = "2";
    auto data = dataDocumentManager->readDocument(metaDoc);
    auto dict = structure::WSDONObjectDict(data->documentData->object);
    auto id = dict["id"];
    auto name = dict["name"];
}

void Table::writeIndexDocument(std::string key) {
    auto indexDocumentManager = std::make_shared<IndexDocumentManager>();
    indexDocumentManager->writeDocument((*indexDocuments)[key]);
}
