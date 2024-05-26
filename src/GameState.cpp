#include <iostream>
#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"

namespace ToadCode {

    GameState::GameState(GameDataRef data)
        : _data(data) {}


    void GameState::init() {
        if (!_hitSoundBuffer.loadFromFile(SOUND_HIT_FILEPATH)) {
            std::cerr << "Error loading sound effect: Hit.wav" << std::endl;
        }
        if (!_pointSoundBuffer.loadFromFile(SOUND_POINT_FILEPATH)) {
            std::cerr << "Error loading sound effect: Point.wav" << std::endl;
        }
        if (!_wingSoundBuffer.loadFromFile(SOUND_WING_FILEPATH)) {
            std::cerr << "Error loading sound effect: Wing.wav" << std::endl;
        }

        _hitSound.setBuffer(_hitSoundBuffer);
        _pointSound.setBuffer(_pointSoundBuffer);
        _wingSound.setBuffer(_wingSoundBuffer);

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
        _data->assets.loadTexture("Scoring Pipe",
                                  SCORING_PIPE_FILEPATH);

        _data->assets.loadFont("Flappy Font",
                               FLAPPY_FONT_FILEPATH);

        _pipe  = new Pipe(_data);
        _land  = new Land(_data);
        _bird  = new Bird(_data);
        _flash = new Flash(_data);
        _hud   = new HUD(_data);

        _background.setTexture(_data->assets.getTexture("Game Background"));

        _score = 0;
        _hud->updateScore(_score);

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
                    _wingSound.play();
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

                _pipe->spawnScoringPipe();

                _clock.restart();
            }
            _bird->update(dt);
            std::vector<sf::Sprite> landSprites = _land->getSprites();
            for (size_t i = 0; i < landSprites.size(); i++) {
                if (_collision.checkSpriteCollision(_bird->getSprite(), 0.7f, landSprites.at(i), 1.0f)) {
                    _gameState = GameStates::eGameOver;
                    _clock.restart();

                    _hitSound.play();
                }
            }

            std::vector<sf::Sprite> pipeSprites = _pipe->getSprites();
            for (size_t i = 0; i < pipeSprites.size(); i++) {
                if (_collision.checkSpriteCollision(_bird->getSprite(), 0.55f, pipeSprites.at(i), 1.0f)) {
                    _gameState = GameStates::eGameOver;
                    _clock.restart();

                    _hitSound.play();
                }
            }

            if (_gameState == GameStates::ePlaying) {
                std::vector<sf::Sprite>& scoringSprites = _pipe->getScoringSprites();
                for (size_t i = 0; i < scoringSprites.size(); i++) {
                    if (_collision.checkSpriteCollision(_bird->getSprite(), 0.55f, scoringSprites.at(i), 1.0f)) {
                        _score++;
                        // std::cout << "Score: " << _score << std::endl;
                        _hud->updateScore(_score);
                        scoringSprites.erase(scoringSprites.begin() + i);

                        _pointSound.play();
                    }
                }
            }
        }

        if (_gameState == GameStates::eGameOver) {
            _flash->show(dt);
            if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
                _data->machine.addState(StateRef(new GameOverState(_data, _score)), true);
            }
        }
    }

    void GameState::draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _pipe->drawPipes();
        _land->drawLand();
        _bird->draw();

        _flash->draw();
        _hud->draw();

        _data->window.display();
    }

}
