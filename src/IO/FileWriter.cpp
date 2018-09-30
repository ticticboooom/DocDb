//
// Created by Kyle on 30/09/2018.
//

#include "FileWriter.h"

FileWriter::FileWriter(std::string path) {
    stream = std::ofstream();
    stream.open(path,  std::ios::out | std::ios::trunc);
}

void FileWriter::writeString(std::string str) {
    stream.seekp(std::ios::beg);
    stream.write(str.c_str(), str.length());
}

FileWriter::~FileWriter() {
    stream.flush();
    stream.close();
}
