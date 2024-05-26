#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#define SCREEN_WIDTH  768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 2.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "resources/res/Splash-Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH    "resources/res/sky.png"
#define GAME_BACKGROUND_FILEPATH         "resources/res/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH    "resources/res/sky.png"

#define GAME_TITLE_FILEPATH  "resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "resources/res/PlayButton.png"

#define PIPE_UP_FILEPATH   "resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "resources/res/PipeDown.png"

#define LAND_FILEPATH "resources/res/Land.png"

#define BIRD_FRAME_1_FILEPATH "resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "resources/res/bird-04.png"

#define PIPE_MOVEMENT_SPEED  200.0f
#define PIPE_SPAWN_FREQUENCY 0.8f

#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL   1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING  3

#define GRAVITY         350.0f
#define FLYING_SPEED    350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED  100.0f

enum GameStates {
    eReady,
    ePlaying,
    eGameOver
};

#endif //DEFINITIONS_HPP