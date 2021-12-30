//
// Created by serja on 09/12/2021.
//

#ifndef ESEMPIO_FILEMANAGER_H
#define ESEMPIO_FILEMANAGER_H


#include "Subject.h"
#include "iostream"
#include "list"
#include "ResourceFile.h"
#include "vector"

class FileManager : public Subject {

private:
    std::list <Observer *> observers;

    std::string fileName;

    std::vector<ResourceFile *> files;

    int bitAttuale, bitCaricati, fileCaricati, bitTotali, fileTot;



public:
    FileManager();

    virtual ~FileManager();

    void attach(Observer *o) override;

    void detach(Observer *o) override;

    void notify() override ;

    std::list<Observer*> &getObserver();

    void downloadFiles(std::vector<ResourceFile *> r);

    int getBitCaricati();

    int getFileCaricati();

    int getTotBit();

    int getFileTotali();

    bool tCaricato();



 ///funzione che chiamo in notify che mi dice la percentuale di caricamento
};

#endif //ESEMPIO_FILEMANAGER_H
