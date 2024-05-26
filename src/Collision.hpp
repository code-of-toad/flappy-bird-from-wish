#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SFML/Graphics.hpp>

namespace ToadCode {

    class Collision {
    public:
        Collision();
        bool checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
    };

}

#endif //COLLISION_HPP
