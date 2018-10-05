//
// Created by Kyle on 30/09/2018.
//

#include "DocumentUtility.h"
#include "../../../IO/FileSystem/CrossFileSystemUtility.h"

std::string DocumentUtility::rootDirectory = "";
std::string DocumentUtility::tableDirectory = "";
const std::string DocumentUtility::fileExtension = ".wsdon";
std::string DocumentUtility::generatePath(std::shared_ptr<structure::DataDocument> doc) {
    std::string path;
    path += getSegment(rootDirectory);
    path += getSegment(tableDirectory);
    path += getSegment(doc->tableIdentifier);
    CrossFileSystemUtility::createDirectory(path);
    path += doc->primaryIndexValue;
    path += fileExtension;
    return path;
}

void DocumentUtility::initialise() {
    //TODO make configurable
    rootDirectory = "C:\\DocDB_DataDirectory";
    tableDirectory = "Tables";

    CrossFileSystemUtility::createDirectory(rootDirectory + "\\" + tableDirectory);
}

std::string DocumentUtility::generatePath(std::shared_ptr<structure::DocumentMetaData> doc) {
    std::string path;
    path += getSegment(rootDirectory);
    path += getSegment(tableDirectory);
    path += getSegment(doc->tableIdentifier);
    path += doc->primaryIndexValue;
    path+= fileExtension;
    return path;
}

std::string DocumentUtility::getSegment(std::string segment) {
    return segment + "\\";
}

