//
// Created by Kyle on 30/09/2018.
//

#include "DocumentUtility.h"
#include "../../../IO/FileSystem/CrossFileSystemUtility.h"

std::string DocumentUtility::rootDirectory = "";
std::string DocumentUtility::tableDirectory = "";

std::string DocumentUtility::generatePath(std::shared_ptr<structure::DataDocument> doc) {
    std::string path;
    path += rootDirectory;
    path += "\\";
    path += tableDirectory;
    path += "\\";
    path += doc->tableIdentifier;
    path += "\\";
    CrossFileSystemUtility::createDirectory(path);
    path += doc->primaryIndexValue;
    path += ".wsdon";
    return path;
}

void DocumentUtility::initialise() {
    //TODO make configurable
    rootDirectory = "C:\\DocDB_DataDirectory";
    tableDirectory = "Tables";

    CrossFileSystemUtility::createDirectory(rootDirectory + "\\" + tableDirectory);
}
