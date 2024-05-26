#ifndef PIPE_HPP
#define PIPE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace ToadCode {
    class Pipe {
        GameDataRef             _data;
        std::vector<sf::Sprite> _pipeSprites;
        std::vector<sf::Sprite> _scoringPipes;
        int                     _landHeight;
        int                     _pipeSpawnYOffset;
    public:
        Pipe(GameDataRef data);
        void                           spawnPipeBottom();
        void                           spawnPipeTop();
        void                           spawnPipeInvisible();
        void                           spawnScoringPipe();
        void                           movePipes(float dt);
        void                           drawPipes();
        void                           randomizePipeOffset();
        const std::vector<sf::Sprite>& getSprites() const;
        std::vector<sf::Sprite>& getScoringSprites();
    };
}

#endif //PIPE_HPP