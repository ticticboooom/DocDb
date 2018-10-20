//
// Created by Kyle on 30/09/2018.
//

#include "PathUtility.h"
#include "../FileSystem/CrossFileSystemUtility.h"
#include "../../DocumentManagement/Documents/Data/DataDocumentManager.h"
#include "../FileReader.h"
#include "../../WSDON/WSDONParser.h"
#include "../FileWriter.h"
#include "../../WSDON/WSDONSerializer.h"
#include "../../WSDON/Structure/WSDONObjectDict.h"


std::string PathUtility::rootDirectory;
std::string PathUtility::tableDirectory;
std::string PathUtility::fileExtension;
std::string PathUtility::indexDirectory;
std::string PathUtility::indexPrefix;
std::string PathUtility::indexSignaturePrefix;
std::string PathUtility::indexSignatureDirectory;

std::string PathUtility::generatePath(std::shared_ptr<structure::DataDocument> doc) {
    auto path = generateBasePath();
    path += getSegment(tableDirectory);
    path += getSegment(doc->tableIdentifier);
    CrossFileSystemUtility::createDirectory(path);
    path += doc->primaryIndexValue;
    path += fileExtension;
    return path;
}

void PathUtility::initialise() {
    auto currentDir = CrossFileSystemUtility::getCurrentWorkingDirectory();
    const auto configPath = currentDir + "/docdb.config.wsdon";
    auto configDocument = readParseDocument(configPath);
    auto obj = structure::WSDONObjectDict(configDocument->object);
    rootDirectory = obj["RootDirectory"].getBasic();
    indexDirectory = obj["IndexDirectory"].getBasic();
    indexPrefix = obj["IndexPrefix"].getBasic();
    tableDirectory = obj["TableDirectory"].getBasic();
    fileExtension = obj["FileExtension"].getBasic();
    indexSignaturePrefix = obj["IndexSignaturePrefix"].getBasic();
    indexSignatureDirectory = obj["IndexSignatureDirectory"].getBasic();
    CrossFileSystemUtility::createDirectory(getSegment(rootDirectory) + getSegment(tableDirectory));
    CrossFileSystemUtility::createDirectory(generateBasePath() + getSegment(indexSignatureDirectory));
}

std::string PathUtility::generatePath(std::shared_ptr<structure::DocumentMetaData> doc) {
    auto path = generateBasePath();
    path += getSegment(tableDirectory);
    path += getSegment(doc->tableIdentifier);
    path += doc->primaryIndexValue;
    path += fileExtension;
    return path;
}

std::string PathUtility::getSegment(std::string segment) {
    if (segment == "/" || segment.empty()) {
        return segment;
    }
    if (segment[segment.length() - 1] != '/') {
        return segment + "/";
    }
    return segment;
}

std::shared_ptr<structure::WSDONDocument> PathUtility::readParseDocument(std::string path) {
    auto fileReader = std::make_shared<FileReader>(path);
    auto fileContents = fileReader->readContents();
    auto document = WSDONParser::parse(fileContents);
    auto documentPtr = std::make_shared<structure::WSDONDocument>(document);
    return documentPtr;
}


std::string PathUtility::generateIndexPath(std::shared_ptr<structure::IndexDocumentMetaData> doc) {
    auto path = generateBasePath();
    path += getSegment(indexDirectory);
    path += indexPrefix + doc->tableName + "_" + doc->IndexedColumnName;
    path += fileExtension;
    return path;
}

std::string PathUtility::generateBasePath() {
    std::string path;
    path += getSegment(rootDirectory);
    return path;
}

void PathUtility::writeSerializeDocument(std::shared_ptr<structure::WSDONDocument> doc, std::string path) {
    auto fw = std::make_shared<FileWriter>(path);
    auto str = WSDONSerializer::serialize(doc);
    fw->writeString(str);
}

std::string PathUtility::generatePath(std::shared_ptr<structure::IndexSignatureDocumentMetaData> doc) {
    auto path = generateBasePath();
    path += getSegment(indexSignatureDirectory);
    path += indexSignaturePrefix + "_" + doc->tableName + fileExtension;
    return path;
}

std::string PathUtility::generatePath(std::shared_ptr<structure::tables::TableInitData> data) {
    auto path = generateBasePath();
    path += getSegment(tableDirectory);
    path += getSegment(data->name);
    return path;
}
