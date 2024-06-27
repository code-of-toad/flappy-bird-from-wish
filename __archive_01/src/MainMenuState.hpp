#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace ToadCode {

    class MainMenuState : public State {
        GameDataRef _data;
        sf::Sprite  _background;
        sf::Sprite  _title;
        sf::Sprite  _playButton;
    public:
        MainMenuState(GameDataRef data);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };

}

#endif //MAINMENUSTATE_HPP
