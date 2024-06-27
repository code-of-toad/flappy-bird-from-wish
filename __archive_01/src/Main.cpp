#include <iostream>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

using std::cout, std::endl, std::string;

int main() {
    ToadCode::Game game(SCREEN_WIDTH,
                        SCREEN_HEIGHT,
                        "Flappy Bird From Wish");

    return EXIT_SUCCESS;
}