#include "ResourceFile.h"


ResourceFile::ResourceFile(std::string name, int byte) {
    this->byte = byte;
    this->risCaricata = false;
    this->fileName = name;
    risCaricata = false;
}

const std::string &ResourceFile::getFileName() const {
    return fileName;
}

int ResourceFile::getByte() const {
    return byte;
}

bool ResourceFile::getFCaricato() {
    return risCaricata;
}
void  ResourceFile::setFCaricato() {
    ResourceFile::risCaricata = true;
}