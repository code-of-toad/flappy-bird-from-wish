#include <iostream>
#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

namespace ToadCode {
    GameOverState::GameOverState(GameDataRef data)
        : _data(data) {}

    void GameOverState::init() {
        _data->assets.loadTexture("Game Over Background",
                                  GAME_OVER_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assets.getTexture("Game Over Background"));
    }

    void GameOverState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _data->window.close();
            }
        }
    }

    void GameOverState::update(float dt) {
    }

    void GameOverState::draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }

}