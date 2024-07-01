cmake_minimum_required(VERSION 3.28)
project(flappy-bird-from-wish)

set(CMAKE_CXX_STANDARD 17)

add_executable(flappy-bird-from-wish
        src/Main.cpp
        src/State.hpp
        src/StateMachine.cpp
        src/StateMachine.hpp
        src/AssetManager.cpp
        src/AssetManager.hpp
        src/InputManager.cpp
        src/InputManager.hpp
        src/Game.cpp
        src/Game.hpp
        src/_DEFINITIONS.hpp
        src/SplashState.cpp
        src/SplashState.hpp
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
target_link_libraries(flappy-bird-from-wish
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)
################################