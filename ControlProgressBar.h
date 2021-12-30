//
// Created by serja on 09/12/2021.
//

#ifndef ESEMPIO_CONTROLPROGRESSBAR_H
#define ESEMPIO_CONTROLPROGRESSBAR_H

//#include "Observer.h"
#include "FileManager.h"
//#include "ProgressBar.h"
#include "SFML/Graphics.hpp"
#include "vector"


class ControlProgressBar {
private:
    FileManager &subject_;
    sf::RenderWindow window;
    int bPercentuale;
    int fPercentuale;
    sf::Text text;


public:
    ControlProgressBar(std::vector<ResourceFile *> r, FileManager &subject, unsigned int width = 300, unsigned int lenght = 50 );//40

    virtual ~ControlProgressBar();

    int init();

    int run();

    sf::RenderWindow &getWindow();

    std::vector<ResourceFile *> r;
};


#endif //ESEMPIO_CONTROLPROGRESSBAR_H
