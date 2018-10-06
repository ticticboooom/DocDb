//
// Created by Kyle on 30/09/2018.
//

#include "FileReader.h"

std::string FileReader::readContents() {
    std::string data;
    auto line = std::string();
    while (getline(stream, line)) {
        data += line + "\n";
    }
    data.erase(data.length() - 1);
    return data;
}

FileReader::FileReader(std::string path) {
    stream = std::ifstream();
    stream.open(path);
}

FileReader::~FileReader() {
    stream.close();
}
