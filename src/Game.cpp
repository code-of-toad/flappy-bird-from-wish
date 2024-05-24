#include "Game.hpp"

namespace ToadCode {

    Game::Game(const int width, const int height, const std::string& title) {
        _data->window.create(sf::VideoMode(width, height),
                             title,
                             sf::Style::Close | sf::Style::Titlebar);
        _data->machine.addState(StateRef(new SplashState(_data)));
        _run();
    }

    void Game::_run() {
        float newTime, frameTime, interpolation;
        float currentTime = _clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (_data->window.isOpen()) {
            _data->machine.processStateChanges();
            newTime = _clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= _dt) {
                _data->machine.getActiveState()->handleInput();
                _data->machine.getActiveState()->update(_dt);
                accumulator -= _dt;
            }

            interpolation = accumulator / _dt;
            _data->machine.getActiveState()->draw(interpolation);
        }
    }

}