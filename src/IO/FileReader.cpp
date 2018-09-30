//
// Created by Kyle on 30/09/2018.
//

#include "FileReader.h"

std::string FileReader::readContents() {
    stream.seekg(0, std::ios::end);
    auto size = stream.tellg();

    stream.seekg(0, std::ios::beg);
    char* buffer = new char[size];
    stream.read(buffer, size);

    return std::string(buffer);
}

FileReader::FileReader(std::string path) {
    stream = std::ifstream();
    stream.open(path);
}

FileReader::~FileReader() {
    stream.close();
}
