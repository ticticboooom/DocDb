//
// Created by Kyle on 30/09/2018.
//

#include <sys/stat.h>
#include "CrossFileSystemUtility.h"


void CrossFileSystemUtility::createDirectory(std::string path) {
    if (directoryExists(path)){
        return;
    }
    auto command = std::string("mkdir  \"") + path + "\"";
    system(command.c_str());
}

bool CrossFileSystemUtility::directoryExists(std::string path) {
    struct stat info;

    if(stat(path.c_str(), &info ) != 0)
    return false;
    else if(info.st_mode & S_IFDIR)
        return true;
    else
        return false;
}
