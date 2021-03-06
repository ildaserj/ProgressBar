#ifndef ESEMPIO_CONTROLPROGRESSBAR_H
#define ESEMPIO_CONTROLPROGRESSBAR_H

#include "FileManager.h"
#include "SFML/Graphics.hpp"
#include "vector"


class ControlProgressBar {
private:
    FileManager &subject;
    sf::RenderWindow window;
    std::vector<ResourceFile *> r;

public:
    ControlProgressBar(FileManager &subject, unsigned int width = 300, unsigned int lenght = 50);//40

    virtual ~ControlProgressBar();

    int init();

    int run();

    sf::RenderWindow &getWindow();


};


#endif //ESEMPIO_CONTROLPROGRESSBAR_H
