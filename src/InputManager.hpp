#pragma once

#include <SFML/Graphics.hpp>

namespace cot {

    class InputManager {
    public:
        InputManager()  = default;
        ~InputManager() = default;

        bool isSpriteClicked(const sf::Sprite& sprite,
                             const sf::Mouse::Button& button,
                             const sf::RenderWindow& window);

        sf::Vector2i getMousePos(const sf::RenderWindow& window);
    };

}