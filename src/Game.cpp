#include "Game.hpp"

namespace ToadCode {

    Game::Game(const int width, const int height, const std::string& title) {
        _data->window.create(sf::VideoMode(width, height),
                             title,
                             sf::Style::Close | sf::Style::Titlebar);
    }

    void Game::_run() {
        float newTime, frameTime, interpolation;
        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen()) {
            this->_data->machine.processStateChanges();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= this->_dt) {
                this->_data->machine.getActiveState()->handleInput();
                this->_data->machine.getActiveState()->update(this->_dt);
                accumulator -= this->_dt;
            }

            interpolation = accumulator / this->_dt;
            this->_data->machine.getActiveState()->draw(interpolation);
        }
    }

}