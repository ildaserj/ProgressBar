//
// Created by serja on 09/12/2021.
//

#ifndef ESEMPIO_RESOURCEFILE_H
#define ESEMPIO_RESOURCEFILE_H

#include "iostream"

class ResourceFile {
private:
    std::string fileName;
    int byte;
    bool risCaricata;

public:
    ResourceFile(std::string name, int byte);
    const std::string &getFileName() const;
    int getByte() const;
    bool getFCaricato();
    void setFCaricato();


};


#endif //ESEMPIO_RESOURCEFILE_H
