#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace ToadCode {

    class GameOverState : public State {
        GameDataRef _data;
        sf::Sprite  _background;
    public:
        GameOverState(GameDataRef data);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };

}

#endif //GAMEOVERSTATE_HPP
