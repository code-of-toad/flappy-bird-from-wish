#include "InputManager.hpp"

namespace cot {

    bool InputManager::isSpriteClicked(const sf::Sprite& sprite,
                                       const sf::Mouse::Button& button,
                                       const sf::RenderWindow& window) {
        if (sf::Mouse::isButtonPressed(button)) {
            sf::IntRect tempRect(sprite.getPosition().x, sprite.getPosition().y,
                                 sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
            if (tempRect.contains(sf::Mouse::getPosition(window))) {
                return true;
            }
        }
        return false;
    }

    sf::Vector2i InputManager::getMousePos(const sf::RenderWindow& window) {
        return sf::Mouse::getPosition(window);
    }


}