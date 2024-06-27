#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace ToadCode {

    class HUD {
        GameDataRef _data;
        sf::Text    _scoreText;
    public:
        HUD(GameDataRef data);
        void draw();
        void updateScore(int score);
    };

}

#endif //HUD_HPP
