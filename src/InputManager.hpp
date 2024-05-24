#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace ToadCoad {

    class InputManager {
    public:
        InputManager()  = default;
        ~InputManager() = default;

        bool isSpriteClicked(sf::Sprite        obj,
                             sf::Mouse::Button button,
                             sf::RenderWindow  window);

        sf::Vector2i getMousePosition(const sf::RenderWindow& window);
    };

}


#endif //INPUTMANAGER_HPP
