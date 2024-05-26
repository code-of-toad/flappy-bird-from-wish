#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SFML/Graphics.hpp>

namespace ToadCode {

    class Collision {
    public:
        Collision();
        bool checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
        bool checkSpriteCollision(sf::Sprite sprite1, float scale1,
                                  sf::Sprite sprite2, float scale2);
    };

}

#endif //COLLISION_HPP
