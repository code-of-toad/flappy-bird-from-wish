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
        _data->assets.loadTexture("Pipe Up",
                                  PIPE_UP_FILEPATH);
        _data->assets.loadTexture("Pipe Down",
                                  PIPE_DOWN_FILEPATH);
        _data->assets.loadTexture("Land",
                                  LAND_FILEPATH);
        _data->assets.loadTexture("Bird Frame 1",
                                  BIRD_FRAME_1_FILEPATH);
        _data->assets.loadTexture("Bird Frame 2",
                                  BIRD_FRAME_2_FILEPATH);
        _data->assets.loadTexture("Bird Frame 3",
                                  BIRD_FRAME_3_FILEPATH);
        _data->assets.loadTexture("Bird Frame 4",
                                  BIRD_FRAME_4_FILEPATH);

        _pipe = new Pipe(_data);
        _land = new Land(_data);
        _bird = new Bird(_data);

        _background.setTexture(_data->assets.getTexture("Game Background"));
    }

    void GameState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _data->window.close();
            }
            if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
                _bird->tap();
            }
        }
    }

    void GameState::update(float dt) {
        _pipe->movePipes(dt);
        _land->moveLand(dt);
        if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
            _pipe->randomizePipeOffset();

            _pipe->spawnPipeInvisible();
            _pipe->spawnPipeBottom();
            _pipe->spawnPipeTop();

            _clock.restart();
        }
        _bird->animate(dt);
        _bird->update(dt);
    }

    void GameState::draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _pipe->drawPipes();
        _land->drawLand();
        _bird->draw();
        _data->window.display();
    }

}