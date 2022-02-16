#include "ControlProgressBar.h"
#include <iostream>


ControlProgressBar::ControlProgressBar(FileManager &subject, unsigned int widht, unsigned int height) :
        window(sf::VideoMode(widht, height), "", sf::Style::Close), subject(subject) {


    auto desktop = sf::VideoMode::getDesktopMode();
    std::cout << "X" << desktop.width / 2 - window.getSize().x / 2 << std::endl;
    std::cout << "Y" << desktop.height / 2 - window.getSize().y / 2 << std::endl;
    window.setPosition(sf::Vector2i(desktop.width / 2 - window.getSize().x / 2,
                                    desktop.height / 2 - window.getSize().y / 2));
}

int ControlProgressBar::init() {
    window.setTitle("Download: press ENTER");

    window.clear();
    window.display();

    while (window.isOpen()) {
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
    subject.downloadFiles();
    if (subject.tCaricato()) {
        window.setTitle("");

        window.clear();
        window.display();
    }
    return 0;
}

ControlProgressBar::~ControlProgressBar() {}

sf::RenderWindow &ControlProgressBar::getWindow() {
    return window;
}
