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

        _gameState = GameStates::eReady;
    }

    void GameState::handleInput() {
        sf::Event event{};
        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _data->window.close();
            }
            if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
                if (_gameState != GameStates::eGameOver) {
                    _gameState = GameStates::ePlaying;
                    _bird->tap();
                }
            }
        }
    }

    void GameState::update(float dt) {
        if (_gameState != GameStates::eGameOver) {
            _bird->animate(dt);
            _land->moveLand(dt);
        }

        if (_gameState == GameStates::ePlaying) {
            _pipe->movePipes(dt);
            if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
                _pipe->randomizePipeOffset();

                _pipe->spawnPipeInvisible();
                _pipe->spawnPipeBottom();
                _pipe->spawnPipeTop();

                _clock.restart();
            }
            _bird->update(dt);

            std::vector<sf::Sprite> landSprites = _land->getSprites();
            for (size_t i = 0; i < landSprites.size(); i++) {
                if (_collision.checkSpriteCollision(_bird->getSprite(), landSprites.at(i))) {
                    _gameState = GameStates::eGameOver;
                }
            }

            std::vector<sf::Sprite> pipeSprites = _pipe->getSprites();
            for (size_t i = 0; i < pipeSprites.size(); i++) {
                if (_collision.checkSpriteCollision(_bird->getSprite(), pipeSprites.at(i))) {
                    _gameState = GameStates::eGameOver;
                }
            }
        }
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