//
// Created by Kyle on 30/09/2018.
//

#include <sys/stat.h>
#include "CrossFileSystemUtility.h"

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

bool CrossFileSystemUtility::createDirectory(std::string path) {
    if (path[path.length() - 1] != '/'){
        path += '/';
    }
    return createAllDirectory(path);
}

bool CrossFileSystemUtility::directoryExists(std::string path) {
    struct stat info{};

    return stat(path.c_str(), &info) != 0 ? false : (info.st_mode & S_IFDIR) != 0;
}

bool CrossFileSystemUtility::createAllDirectory(std::string path) {
    auto i = 0u;
    auto found = path.find('/', i);
    auto success = false;
    while (found != std::string::npos) {
        success = createSubDirectory(std::string(path.begin(), path.begin() + found));
        i = found + 1;
        found = path.find('/', i);
    }
    return success;
}

bool CrossFileSystemUtility::createSubDirectory(std::string path) {
    auto commandResult = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH);
    if (commandResult == -1) {
        auto err = errno;
        if (err != EEXIST){
            return false;
        }
    }
    return true;
}

std::string CrossFileSystemUtility::getCurrentWorkingDirectory() {
    auto currentDir = new char[FILENAME_MAX];
    GetCurrentDir(currentDir, FILENAME_MAX);
    return std::string(currentDir);
}
