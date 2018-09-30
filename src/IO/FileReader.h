//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_FILEREADER_H
#define DOCDB_FILEREADER_H


#include <string>
#include <fstream>

class FileReader {
public:
    FileReader(std::string path);
    ~FileReader();
    std::string readContents();
private:
    std::ifstream stream;
};


#endif //DOCDB_FILEREADER_H
