#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace cot {

    struct GameData {
        sf::RenderWindow window;
        StateMachine machine;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
        GameDataRef _data = std::make_shared<GameData> ();
        const float _dt = 1.0f / 60.0f;
        sf::Clock   _clock;

        void _run() const;
    public:
        Game(int width, int height, const std::string& title);
    };

}