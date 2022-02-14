
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

/*
int main() {

    sf::Vector2i screen(800, 600);
    sf::RenderWindow window(sf::VideoMode(screen.x, screen.y),"Progressbar");

    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    int hp = 20;
    sf:: RectangleShape progressbar;

    progressbar.setFillColor(sf::Color::Blue);
    //std::cout << "blue" << std::endl;
    progressbar.setOutlineThickness(2);
    progressbar.setOutlineColor(sf::Color::Red);
    //std::cout << "red" << std::endl;

    progressbar.setPosition(200,50);

    while (window.isOpen()) {
        sf::Event event;
        std::cout<< "pigia";
        while (window.pollEvent(event)) {
            switch (event.type) {
                std::cout<<"closed"<<std::endl;
            case sf::Event::Closed :
                window.close();
                break;
              case sf::Event::KeyReleased:
                  std::cout<<"Entera"<<std::endl;
                if (event.key.code == sf::Keyboard::A) {
                    hp -= 1;
                    std::cout << hp << std::endl;
                }
                if (hp <= 0) {
                window.close();
                }
            }
        }

        progressbar.setSize(sf::Vector2f(hp * 20, 20));
        window.draw(progressbar);
        //window.draw(shape);
        window.display();
        window.clear();
    }
    return 0;
}

*/