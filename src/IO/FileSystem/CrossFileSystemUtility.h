//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_CROSSFILESYSTEMUTILITY_H
#define DOCDB_CROSSFILESYSTEMUTILITY_H


#include <string>

class CrossFileSystemUtility {
public:
    static void createDirectory(std::string path);
    static bool directoryExists(std::string  path);
};


#endif //DOCDB_CROSSFILESYSTEMUTILITY_H
