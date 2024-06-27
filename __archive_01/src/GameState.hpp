#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"

namespace ToadCode {

    class GameState : public State {
        GameDataRef _data;
        sf::Sprite  _background;
        Pipe*       _pipe;
        Land*       _land;
        Bird*       _bird;
        Collision   _collision;
        Flash*      _flash;
        HUD*        _hud;
        sf::Clock   _clock;
        int         _gameState;
        int         _score;

        sf::SoundBuffer _hitSoundBuffer;
        sf::SoundBuffer _pointSoundBuffer;
        sf::SoundBuffer _wingSoundBuffer;
        sf::Sound       _hitSound;
        sf::Sound       _pointSound;
        sf::Sound       _wingSound;
    public:
        GameState(GameDataRef data);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };

}

#endif //GAMESTATE_HPP