#include <iostream>
#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

namespace ToadCode {
    SplashState::SplashState(GameDataRef data)
        : _data(data) {}

    void SplashState::init() {
        _data->assets.loadTexture("Splash State Background",
                                  SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assets.getTexture("Splash State Background"));
    }

    void SplashState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _data->window.close();
            }
        }
    }

    void SplashState::update(float dt) {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
            _data->machine.addState(StateRef(new MainMenuState(_data)), true);
        }
    }

    void SplashState::draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }

}