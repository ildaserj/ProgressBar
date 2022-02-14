//
// Created by serja on 09/12/2021.
//

#include "FileManager.h"

#include <utility>
#include "SFML/Graphics.hpp"


    FileManager::FileManager(std::vector<ResourceFile *> r): byteCaricati(0), fileCaricati(0), byteTotali(0), r(r) {}

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



    void FileManager::downloadFiles() {

    ///calcolo byte totali
        int totBit = 0;
        fileTot = r.size();
        for(int i = 0 ; i < r.size(); i++ ){
            totBit += r[i]->getByte();
        }
        byteTotali=totBit;
    ///caricamento risource file
        for(int i = 0; i < r.size(); i++) {
            std::cout << "Download file: "<< r[i]->getFileName() << std::endl;
            files.push_back(r[i]);
            files[i]->setFCaricato();
            byteAttuale = files[i]->getByte();
            fileCaricati++;

            byteCaricati += r[i]->getByte();
            std::cout<<"notify "<< i <<std::endl;
            notify();

//            sf::sleep(sf::seconds(1));

        }

    }

     int FileManager::getByteCaricati()  {
        return byteCaricati;
    }
    int FileManager::getFileCaricati() {
        return  fileCaricati;
    }

    int FileManager::getTotBit() {
        return byteTotali;
    }

    int FileManager::getFileTotali() {
        return fileTot;
    }
//////
    bool FileManager::tCaricato() {
        bool caricato = false;
        for(int i =0 ; i < files.size(); i++){
            if (files[i]->getFCaricato()){
                caricato = true;
            }
            else {
                caricato = false;
            }
        }
    return caricato;
    }

    std::list<Observer*> &FileManager::getObserver() {
        return observers;
}