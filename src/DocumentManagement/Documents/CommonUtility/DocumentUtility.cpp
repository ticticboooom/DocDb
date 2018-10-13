//
// Created by Kyle on 30/09/2018.
//

#include "DocumentUtility.h"
#include "../../../IO/FileSystem/CrossFileSystemUtility.h"
#include "../Data/DataDocumentManager.h"
#include "../../../IO/FileReader.h"
#include "../../../WSDON/WSDONParser.h"
#include "../../../IO/FileWriter.h"
#include "../../../WSDON/WSDONSerializer.h"


std::string DocumentUtility::rootDirectory;
std::string DocumentUtility::tableDirectory;
std::string DocumentUtility::fileExtension;
std::string DocumentUtility::indexDirectory;
std::string DocumentUtility::indexPrefix;

std::string DocumentUtility::generatePath(std::shared_ptr<structure::DataDocument> doc) {

    auto path = generateBasePath();
    path += getSegment(doc->tableIdentifier);
    CrossFileSystemUtility::createDirectory(path);
    path += doc->primaryIndexValue;
    path += fileExtension;
    return path;
}

void DocumentUtility::initialise() {
    auto currentDir = CrossFileSystemUtility::getCurrentWorkingDirectory();
    const auto configPath = currentDir + "/docdb.config.wsdon";
    auto configDocument = readParseDocument(configPath);
    auto obj = configDocument->object->getObject();
    rootDirectory = (*obj)["RootDirectory"].getBasic();
    indexDirectory = (*obj)["IndexDirectory"].getBasic();
    indexPrefix = (*obj)["IndexPrefix"].getBasic();
    tableDirectory = (*obj)["TableDirectory"].getBasic();
    fileExtension = (*obj)["FileExtension"].getBasic();
    CrossFileSystemUtility::createDirectory(rootDirectory + "/" + tableDirectory);
}

std::string DocumentUtility::generatePath(std::shared_ptr<structure::DocumentMetaData> doc) {
    auto path = generateBasePath();
    path += getSegment(doc->tableIdentifier);
    path += doc->primaryIndexValue;
    path += fileExtension;
    return path;
}

std::string DocumentUtility::getSegment(std::string segment) {
    if (segment == "/" || segment.empty()) {
        return segment;
    }
    if (segment[segment.length() - 1] != '/') {
        return segment + "/";
    }
    return segment;
}

std::shared_ptr<structure::WSDONDocument> DocumentUtility::readParseDocument(std::string path) {
    auto fileReader = std::make_shared<FileReader>(path);
    auto fileContents = fileReader->readContents();
    auto document = WSDONParser::parse(fileContents);
    auto documentPtr = std::make_shared<structure::WSDONDocument>(document);
    return documentPtr;
}


std::string DocumentUtility::generateIndexPath(std::shared_ptr<structure::IndexDocumentMetaData> doc) {
    auto path = generateBasePath();
    path += getSegment(indexDirectory);
    path += indexPrefix + doc->tableName + "_" + doc->IndexedColumnName;
    path += fileExtension;
}

std::string DocumentUtility::generateBasePath() {
    std::string path;
    path += getSegment(rootDirectory);
    path += getSegment(tableDirectory);
    return path;
}

void DocumentUtility::writeSerializeDocument(std::shared_ptr<structure::WSDONDocument> doc, std::string path) {
    auto fw = std::make_shared<FileWriter>(path);
    auto str = WSDONSerializer::serialize(doc);
    fw->writeString(str);
}