#include <iostream>
#include <sstream>
#include <utility>
#include "SplashState.hpp"
#include "_DEFINITIONS.hpp"


namespace cot {

    SplashState::SplashState(GameDataRef data)
        : _data(std::move(data)) {}

    void SplashState::init() {
        _data->assets.loadTexture("Splash State Background",
                                  SPALSH_SCENE_BACKGROUND_FILEPATH);
        _bg.setTexture(_data->assets.getTexture("Splash State Background"));
    }

    void SplashState::handleInput() {
        sf::Event event {};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed
                                       || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                _data->window.close();
            }
        }
    }

    void SplashState::update(float dt) {
        if (_clock.getElapsedTime().asSeconds() > SPALSH_STATE_SHOW_TIME) {
            std::cout << "Go To Main Menu\n";
        }
    }

    void SplashState::draw(float dt) {
        _data->window.clear();
        _data->window.draw(_bg);
        _data->window.display();
    }


}