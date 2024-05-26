cmake_minimum_required(VERSION 3.28)
project(sfml-engine-setup)

set(CMAKE_CXX_STANDARD 17)

add_executable(sfml-engine-setup
        src/Main.cpp
        src/State.hpp
        src/StateMachine.hpp
        src/StateMachine.cpp
        src/AssetManager.hpp
        src/AssetManager.cpp
        src/InputManager.hpp
        src/InputManager.cpp
        src/Game.hpp
        src/Game.cpp
        src/DEFINITIONS.hpp
        src/SplashState.hpp
        src/SplashState.cpp
        src/MainMenuState.hpp
        src/MainMenuState.cpp
        src/GameState.hpp
        src/GameState.cpp
        src/GameOverState.hpp
        src/GameOverState.cpp
        src/Pipe.hpp
        src/Pipe.cpp
        src/Land.hpp
        src/Land.cpp
        src/Bird.hpp
        src/Bird.cpp
        src/Collision.hpp
        src/Collision.cpp
)

############# SFML #############
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS REQUIRED
        system
        window
        graphics
        audio
        network
)
target_link_libraries(sfml-engine-setup
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)
################################