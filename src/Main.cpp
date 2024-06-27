#include <iostream>
#include <SFML/Graphics.hpp>

#define SCREEN_W 1024
#define SCREEN_H 1024

using std::cout, std::endl, std::string;

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Flappy Bird From Wish");

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
    }

    return 0;
}