#include <SFML/Graphics.hpp>
#include <iostream>

#define SCRN_WIDTH  1200
#define SCRN_HEIGHT 800

using std::cout, std::endl, std::string, std::vector;

int main() {
    sf::RenderWindow window(sf::VideoMode(SCRN_WIDTH, SCRN_HEIGHT), "sfml works");

    return 0;
}
