#include <iostream>
#include "Pipe.hpp"

namespace ToadCode {

    Pipe::Pipe(GameDataRef data) : _data(data) {
        _landHeight = _data->assets.getTexture("Land").getSize().y;
        _pipeSpawnYOffset = 0;
    }

    void Pipe::spawnPipeBottom() {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
        sprite.setPosition(_data->window.getSize().x,
                           _data->window.getSize().y - sprite.getGlobalBounds().height
                                                     - _pipeSpawnYOffset);
        _pipeSprites.push_back(sprite);
    }

    void Pipe::spawnPipeTop() {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Down"));
        sprite.setPosition(_data->window.getSize().x, - _pipeSpawnYOffset);
        _pipeSprites.push_back(sprite);
    }

    void Pipe::spawnPipeInvisible() {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
        sprite.setPosition(_data->window.getSize().x,
                         _data->window.getSize().y - sprite.getGlobalBounds().height);
        sprite.setColor(sf::Color(0, 0, 0, 0));
        _pipeSprites.push_back(sprite);
    }

    void Pipe::spawnScoringPipe() {
        sf::Sprite sprite(_data->assets.getTexture("Scoring Pipe"));
        sprite.setPosition(_data->window.getSize().x, 0);
        _scoringPipes.push_back(sprite);
    }

    void Pipe::movePipes(float dt) {
        for (size_t i = 0; i < _pipeSprites.size(); i++) {
            if (_pipeSprites.at(i).getPosition().x < 0 - _pipeSprites.at(i).getGlobalBounds().width) {
                _pipeSprites.erase(_pipeSprites.begin() + i);
            }
            else {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                _pipeSprites.at(i).move(-movement, 0);
            }
        }
        // DEBUGGGGGGGG
        // std::cout << "Number of Pipe Sprites: " << _pipeSprites.size() << std::endl;
        // DEBUGGGGGGGG
        for (size_t i = 0; i < _scoringPipes.size(); i++) {
            if (_scoringPipes.at(i).getPosition().x < 0 - _scoringPipes.at(i).getGlobalBounds().width) {
                _scoringPipes.erase(_scoringPipes.begin() + i);
            }
            else {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                _scoringPipes.at(i).move(-movement, 0);
            }
        }
    }

    void Pipe::drawPipes() {
        for (size_t i = 0; i < _pipeSprites.size(); i++) {
            _data->window.draw(_pipeSprites.at(i));
        }
    }

    void Pipe::randomizePipeOffset() {
        _pipeSpawnYOffset = rand() % (_landHeight + 1);
    }

    const std::vector<sf::Sprite>& Pipe::getSprites() const {
        return _pipeSprites;
    }

    std::vector<sf::Sprite>& Pipe::getScoringSprites() {
        return _scoringPipes;
    }



}