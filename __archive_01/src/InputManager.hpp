#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace ToadCode {

    class InputManager {
    public:
        InputManager()  {}
        ~InputManager() {}

        bool isSpriteClicked(sf::Sprite        obj,
                             sf::Mouse::Button button,
                             sf::RenderWindow& window);

        sf::Vector2i getMousePosition(const sf::RenderWindow& window);
    };

}

#endif //INPUTMANAGER_HPP