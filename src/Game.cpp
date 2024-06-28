#include "Game.hpp"

namespace cot {

    Game::Game(const int width, const int height, const std::string& title) {
        _data->window.create(sf::VideoMode(width, height), title,
                             sf::Style::Close | sf::Style::Titlebar);
        _run();
    }

    void Game::_run() const {
        float newTime, frameTime, interpolation;
        float currTime = _clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (_data->window.isOpen()) {
            _data->machine.processStateChanges();
            newTime = _clock.getElapsedTime().asSeconds();
            frameTime = newTime - currTime;
            if (frameTime > 0.25f) frameTime = 0.25f;
            currTime = newTime;

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