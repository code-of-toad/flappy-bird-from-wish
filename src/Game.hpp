#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace ToadCode {

    struct GameData {
        StateMachine     machine;
        sf::RenderWindow window;
        AssetManager     assets;
        InputManager     input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
        const float _dt = 1.0f / 60.0f;
        sf::Clock   _clock;
        GameDataRef _data = std::make_shared<GameData>();
        void _run();
    public:
        Game(int width, int height, const std::string& title);
    };

}

#endif //GAME_HPP