#include <iostream>
#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

namespace ToadCode {
    GameState::GameState(GameDataRef data)
        : _data(data) {}

    void GameState::init() {
        _data->assets.loadTexture("Game Background",
                                  GAME_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assets.getTexture("Game Background"));
    }

    void GameState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _data->window.close();
            }
        }
    }

    void GameState::update(float dt) {
    }

    void GameState::draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }

}