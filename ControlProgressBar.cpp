//
// Created by serja on 09/12/2021.
//

#include "ControlProgressBar.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <thread>







ControlProgressBar::ControlProgressBar(std::vector <ResourceFile *> r_, FileManager &subject, unsigned int widht, unsigned int height ) :
                                                window(sf::VideoMode(widht, height), "", sf::Style::Close),subject_(subject), r(r_){


   // sf::Font font;
   // font.loadFromFile("fonts/OpenSans-Italic.ttf");
   // text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);



    auto desktop = sf::VideoMode::getDesktopMode();
    std::cout<< "X"<<desktop.width /2 - window.getSize().x /2 << std::endl;
    std::cout<< "Y"<<desktop.height /2 - window.getSize().y /2 << std::endl;
    window.setPosition(sf::Vector2i(desktop.width /2 - window.getSize().x /2,
                       desktop.height /2 - window.getSize().y /2));
}

int ControlProgressBar::init() {
    window.setTitle("Download");
    text.setString("Press ENTER to download file");

    window.clear();
    window.draw(text);
    window.display();

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Enter)
                    return run();
        }
    }
    return 0;
}


int ControlProgressBar::run() {
    window.clear();
    window.setTitle("Progress Bar");
    subject_.downloadFiles(r);
    if (subject_.tCaricato()){
        window.setTitle("");
        text.setString("Download completed!");

        window.clear();
        window.draw(text);
        window.display();

        return 0;
    }
}
ControlProgressBar::~ControlProgressBar() {}

sf::RenderWindow &ControlProgressBar:: getWindow() {
    return window;
}
/*
void ControlProgressBar::update(int bitPercentuale, int filePercentuale) {
    bitPercentuale = bitPercentuale;
    progressBar_->setBarra(bPercentuale);
}

void ControlProgressBar::removeMefromTheList() {
    subject_.detach(this);
}
*/