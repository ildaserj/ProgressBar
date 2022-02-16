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

    const int getByte() const;

    const bool getFCaricato() const;

    void setFCaricato();

};

#endif //ESEMPIO_RESOURCEFILE_H
