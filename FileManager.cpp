//
// Created by serja on 09/12/2021.
//

#include "FileManager.h"
#include "SFML/Graphics.hpp"


    FileManager::FileManager(): bitCaricati(0), fileCaricati(0), bitTotali(0) {}

    FileManager:: ~FileManager() {}

    void FileManager::attach(Observer *o) {
        observers.push_back(o);
    }

    void FileManager::detach(Observer *o)  {
        observers.remove(o);
    }

    void FileManager:: notify()  {
    std::list<Observer *>::iterator iterator = observers.begin();

        while (iterator != observers.end()) {
            (*iterator)->update();
            ++iterator;
        }
    }



    void FileManager::downloadFiles(std::vector<ResourceFile *> r) {

    ///calcolo bit totali
        int totBit = 0;
        fileTot = r.size();
        for(int i = 0 ; i < r.size(); i++ ){
            totBit +=r[i]->getBit();
        }
        bitTotali=totBit;
    ///caricamento risource file
        for(int i = 0; i < r.size(); i++) {
        std::cout << "Download file: "<< r[i]->getFileName() << std::endl;

                files.push_back(r[i]);
                files[i]->setFCaricato();
                bitAttuale = files[i]->getBit();
                fileCaricati++;

                bitCaricati += r[i]->getBit();
                //percentualeCaricamento = bitCaricati;
                //filePercentuale = (fileCaricati * 100) / files.size();
                std::cout<<"notify "<< i <<std::endl;
                notify();

                sf::sleep(sf::seconds(1));

        }

    }

     int FileManager::getBitCaricati()  {
        return bitCaricati;
    }
    int FileManager::getFileCaricati() {
        return  fileCaricati;
    }

    int FileManager::getTotBit() {
        return bitTotali;
    }

    int FileManager::getFileTotali() {
        return fileTot;
    }
//////
    bool FileManager::tCaricato() {
        for(int i =0 ; i < files.size(); i++){
            if (files[i]->getFCaricato() != true){
                return false;
            }
            return true;
        }
    }

    std::list<Observer*> &FileManager::getObserver() {
        return observers;
}