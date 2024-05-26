#ifndef BIRD_HPP
#define BIRD_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace ToadCode {

    class Bird {
        GameDataRef              _data;
        sf::Sprite               _birdSprite;
        std::vector<sf::Texture> _animationFrames;
        unsigned int             _animationIterator;
        sf::Clock                _clock;
        sf::Clock                _movementClock;
        int                      _birdState;
        float                    _rotation;
    public:
        Bird(GameDataRef data);
        void draw();
        void animate(float dt);
        void update(float dt);
        void tap();
    };

}

#endif //BIRD_HPP