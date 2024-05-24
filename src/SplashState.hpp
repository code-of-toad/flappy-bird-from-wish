#ifndef SPLASHSTATE_HPP
#define SPLASHSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace ToadCode {

    class SplashState : public State {
        GameDataRef _data;
        sf::Clock   _clock;
        sf::Texture _backgroundTexture;
        sf::Sprite  _background;
    public:
        SplashState(GameDataRef data);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };

}

#endif //SPLASHSTATE_HPP
