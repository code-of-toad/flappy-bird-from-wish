#ifndef FLASH_HPP
#define FLASH_HPP

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace ToadCode {

    class Flash {
        GameDataRef        _data;
        sf::RectangleShape _shape;
        bool               _flashOn;
    public:
        Flash(GameDataRef data);
        void show(float dt);
        void draw();
    };

}

#endif //FLASH_HPP
