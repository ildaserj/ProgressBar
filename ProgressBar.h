

#ifndef ESEMPIO_PROGRESSBAR_H
#define ESEMPIO_PROGRESSBAR_H

#include "Observer.h"
#include "FileManager.h"
#include "SFML/Graphics.hpp"



class ProgressBar : public Observer{
public:
    ProgressBar(FileManager &fileManager, sf::RenderWindow *w,std::string type, unsigned int x, unsigned int y, sf::Color color =sf::Color::Magenta);

    ~ProgressBar();

    virtual void update() override;




private:
    FileManager &fileManager;
    sf::RenderWindow *window;
    sf::RectangleShape rectangleShape;
    unsigned int maxWidth;
    unsigned int maxHeight;
    std::string type;

};


#endif //ESEMPIO_CONTROLPROGRESSBAR_H