#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"

namespace ToadCode {

    class GameState : public State {
        GameDataRef _data;
        sf::Sprite  _background;
        Pipe*       _pipe;
        Land*       _land;
        Bird*       _bird;
        sf::Clock   _clock;
    public:
        GameState(GameDataRef data);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };

}

#endif //GAMESTATE_HPP