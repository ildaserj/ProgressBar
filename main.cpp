#include <SFML/Graphics.hpp>
#include <vector>
#include "ResourceFile.h"
#include "FileManager.h"
#include "ControlProgressBar.h"
#include "ProgressBar.h"

int main(){


    std::vector<ResourceFile *> risorsa(15);
    risorsa[0] = new ResourceFile("Risorsa_01", 4);
    risorsa[1] = new ResourceFile("Risorsa_02", 8);
    risorsa[2] = new ResourceFile("Risorsa_03", 16);
    risorsa[3] = new ResourceFile("Risorsa_04", 4);
    risorsa[4] = new ResourceFile("Risorsa_05", 4);
    risorsa[5] = new ResourceFile("Risorsa_06", 16);
    risorsa[6] = new ResourceFile("Risorsa_07", 8);
    risorsa[7] = new ResourceFile("Risorsa_08", 16);
    risorsa[8] = new ResourceFile("Risorsa_09", 32);
    risorsa[9] = new ResourceFile("Risorsa_10", 4);
    risorsa[10] = new ResourceFile("Risorsa_11", 16);
    risorsa[11] = new ResourceFile("Risorsa_12", 4);
    risorsa[12] = new ResourceFile("Risorsa_13", 4);
    risorsa[13] = new ResourceFile("Risorsa_14", 8);
    risorsa[14] = new ResourceFile("Risorsa_15", 8);


    FileManager *fileManager = new FileManager(risorsa);

    ControlProgressBar controlProgressBar(*fileManager);

    ProgressBar progressBar(*fileManager, &controlProgressBar.getWindow(), "file", 0, 0, sf::Color::Magenta);

    ProgressBar progressBar1(*fileManager, &controlProgressBar.getWindow(), "byte", 0, 30, sf::Color::Blue);

    return controlProgressBar.init();





}