#include "ProgressBar.h"

ProgressBar::ProgressBar(FileManager &fileManager_, sf::RenderWindow *w, std::string type,
                         unsigned int x, unsigned int y, sf::Color color) :
        fileManager(fileManager_), type(std::move(type)), window(w), maxWidth(300), maxHeight(20), numNotify(0){

    fileManager.attach(this);
    rectangleShape.setPosition(sf::Vector2f(x, y));
    rectangleShape.setFillColor(color);

}

ProgressBar::~ProgressBar() {
    fileManager.detach(this);
}


void ProgressBar::update() {
    numNotify++;
    if (type == "file") {
        std::cout << "update file" << std::endl;
        rectangleShape.setSize(
                sf::Vector2f((maxWidth * fileManager.getFileCaricati()) / fileManager.getFileTotali(), maxHeight));
        std::cout << (maxWidth * fileManager.getFileCaricati()) / fileManager.getFileTotali() << " " << maxHeight
                  << std::endl;

        window->draw(rectangleShape);
        window->display();

    }
    if (type == "byte") {
        std::cout << "update byte" << std::endl;
        rectangleShape.setPosition(sf::Vector2f(0, 30));
        rectangleShape.setSize(sf::Vector2f(300, 40));//40
        rectangleShape.setFillColor(sf::Color::Black);

        window->draw(rectangleShape);

        rectangleShape.setFillColor(sf::Color::Blue);
        rectangleShape.setSize(
                sf::Vector2f((maxWidth * fileManager.getByteCaricati()) / fileManager.getTotBit(), maxHeight));
        std::cout << (maxWidth * fileManager.getByteCaricati()) / fileManager.getTotBit() << " " << maxHeight
                  << std::endl;


    }
    window->draw(rectangleShape);
    window->display();
}

int ProgressBar::getNumNotify() const {
    return numNotify;
}