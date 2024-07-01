#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace cot {

    class SplashState final : public State {
        GameDataRef _data;
        sf::Clock   _clock;
        sf::Texture _bgTexture;
        sf::Sprite  _bg;
    public:
        explicit SplashState(GameDataRef data);
        void init()           override;
        void handleInput()    override;
        void update(float dt) override;
        void draw(float dt)   override;
    };

}
