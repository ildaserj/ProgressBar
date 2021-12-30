//
// Created by serja on 09/12/2021.
//

#include "ResourceFile.h"


ResourceFile::ResourceFile(std::string name, int bit) {
    this->bit = bit;
    this->risCaricata = false;
    this->fileName = name;
    risCaricata = false;
}

const std::string ResourceFile::getFileName() const {
    return fileName;
}

int ResourceFile::getBit() const {
    return bit;
}

bool ResourceFile::getFCaricato() {
    return risCaricata;
}
void  ResourceFile::setFCaricato() {
    ResourceFile::risCaricata = true;
}