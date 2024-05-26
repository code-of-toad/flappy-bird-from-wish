#include "Collision.hpp"

namespace ToadCode {

    Collision::Collision() {

    }

    bool Collision::checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2) {
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();

        if (rect1.intersects(rect2)) {
            return true;
        }
        return false;
    }

}