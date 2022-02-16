#ifndef ESEMPIO_FILEMANAGER_H
#define ESEMPIO_FILEMANAGER_H


#include "Subject.h"
#include "iostream"
#include "list"
#include "ResourceFile.h"
#include "vector"

class FileManager : public Subject {

private:
    std::list<Observer *> observers;

    std::string fileName;

    std::vector<ResourceFile *> files;
    std::vector<ResourceFile *> r;//files da caricare

    int byteAttuale, byteCaricati, fileCaricati, byteTotali, fileTot;


public:
    FileManager(std::vector<ResourceFile *> r);

    virtual ~FileManager();

    void attach(Observer *o) override;

    void detach(Observer *o) override;

    void notify() override;

    std::list<Observer *> &getObserver();

    void downloadFiles();

    const int getByteCaricati() const;

    const int getFileCaricati() const;

    const int getTotBit() const;

    const int getFileTotali() const;

    bool tCaricato();
};

#endif //ESEMPIO_FILEMANAGER_H
