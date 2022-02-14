
#include "ProgressBar.h"


ProgressBar::ProgressBar(FileManager &fileManager_, sf::RenderWindow *w, std::string type,
                         unsigned int x, unsigned int y, sf::Color color) :
                         fileManager(fileManager_),type(std::move(type)), window(w), maxWidth(300), maxHeight(20) {

    fileManager.attach(this);
    rectangleShape.setPosition(sf::Vector2f(x, y));
    rectangleShape.setFillColor(color);

}

    ProgressBar:: ~ProgressBar() {
        fileManager.detach(this);
}


    void ProgressBar::update() {

       if (type == "file") {
           std::cout<<"update file"<<std::endl;
           rectangleShape.setSize(sf::Vector2f((maxWidth * fileManager.getFileCaricati()) / fileManager.getFileTotali(), maxHeight));
           std::cout << (maxWidth * fileManager.getFileCaricati()) / fileManager.getFileTotali() << " " << maxHeight
                     << std::endl;

           window->draw(rectangleShape);
           window->display();

       }

       if (type == "byte") {
           std::cout<<"update byte"<<std::endl;
           rectangleShape.setPosition(sf::Vector2f(0, 30));
           rectangleShape.setSize(sf::Vector2f(300,40));//40
           rectangleShape.setFillColor(sf::Color::Black);

           window->draw(rectangleShape);

           rectangleShape.setFillColor(sf::Color::Blue);
           rectangleShape.setSize(sf::Vector2f((maxWidth * fileManager.getByteCaricati()) / fileManager.getTotBit(), maxHeight));
           std::cout << (maxWidth * fileManager.getByteCaricati()) / fileManager.getTotBit() << " " << maxHeight << std::endl;


       }
        window->draw(rectangleShape);
        window->display();
    }
    /*
    void ::ProgressBar::drawPB() {

        sf::Vector2i screen(800, 600);
        hp = 100;
        sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "Progress bar");

        sf::RectangleShape progressbar;
        progressbar.setFillColor(sf::Color::Blue);

        progressbar.setOutlineThickness(2);
        progressbar.setOutlineColor(sf::Color::Red);

        progressbar.setPosition(200, 50);



        while (window.isOpen()) {
            sf::Event event;

            std::cout <<"pigia";

            while (window.waitEvent(event)) {

                    switch (event.type) {
                        std::cout << "prog------ PRESS ENTER TO DOWNLOAD THE FILE------" << std::endl;
                        case sf::Event::Closed:
                            window.close();
                            break;


                        case sf::Event::KeyPressed:
                            std::cout<<"____________________________________________________________________"<<std::endl;
                            if (event.key.code == sf::Keyboard::Enter) {
                                hp -= hpCar;

                            }
                            if (hp <= 0) {
                                window.close();
                            }

                    }


                progressbar.setSize(sf::Vector2f(hp * 5, 20));
                window.draw(progressbar);
                window.display();
                std::cout<<"closed"<<std::endl;

                window.close();
            }
        }
       -- /*

    progressbar.setSize(sf::Vector2f (hp*5, 20));
    window.draw(progressbar);
    window.display();

    } --
*/