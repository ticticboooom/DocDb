//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_CROSSFILESYSTEMUTILITY_H
#define DOCDB_CROSSFILESYSTEMUTILITY_H


#include <string>

class CrossFileSystemUtility {
public:
    static bool createDirectory(std::string path);
    static bool directoryExists(std::string  path);
    static std::string getCurrentWorkingDirectory();
private:
    static bool createSubDirectory(std::string path);
    static bool createAllDirectory(std::string path);
};


#endif //DOCDB_CROSSFILESYSTEMUTILITY_H
