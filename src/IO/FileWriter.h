//
// Created by Kyle on 30/09/2018.
//

#ifndef DOCDB_FILEWRITER_H
#define DOCDB_FILEWRITER_H


#include <string>
#include <fstream>

class FileWriter {
public:
    FileWriter(std::string path);
    ~FileWriter();
    void writeString(std::string str);
private:
    std::ofstream stream;
};


#endif //DOCDB_FILEWRITER_H
