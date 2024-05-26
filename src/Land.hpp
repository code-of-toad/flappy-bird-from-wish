#ifndef LAND_HPP
#define LAND_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace ToadCode {

    class Land {
        GameDataRef             _data;
        std::vector<sf::Sprite> _landSprites;
    public:
        Land(GameDataRef data);
        void                           moveLand(float dt);
        void                           drawLand();
        const std::vector<sf::Sprite>& getSprites() const;
    };

}

#endif //LAND_HPP