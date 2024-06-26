#include "Land.hpp"

namespace ToadCode {

    Land::Land(GameDataRef data) : _data(data) {
        sf::Sprite sprite1(_data->assets.getTexture("Land"));
        sf::Sprite sprite2(_data->assets.getTexture("Land"));

        sprite1.setPosition(0,
                            _data->window.getSize().y - sprite1.getGlobalBounds().height);
        sprite2.setPosition(sprite1.getGlobalBounds().width,
                            _data->window.getSize().y - sprite1.getGlobalBounds().height);
        _landSprites.push_back(sprite1);
        _landSprites.push_back(sprite2);
    }

    void Land::moveLand(float dt) {
        for (size_t i = 0; i < _landSprites.size(); i++) {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            _landSprites.at(i).move(-movement, 0.0f);
            if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getGlobalBounds().width) {
                sf::Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
                _landSprites.at(i).setPosition(position);
            }
        }
    }

    void Land::drawLand() {
        for (size_t i = 0; i < _landSprites.size(); i++) {
            _data->window.draw(_landSprites.at(i));
        }
    }

    const std::vector<sf::Sprite> &Land::getSprites() const {
        return _landSprites;
    }


}