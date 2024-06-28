#include "Game.hpp"

namespace cot {

    Game::Game(const int width, const int height, const std::string& title) {
        _data->window.create(sf::VideoMode(width, height), title,
                             sf::Style::Close | sf::Style::Titlebar);
        _run();
    }

    void Game::_run() const {
        // Get the current time in seconds since the clock started.
        float currTime = _clock.getElapsedTime().asSeconds();

        // Main game loop that continues as long as the window stays open.
        while (_data->window.isOpen()) {
            // Process any state changes (e.g., switching between different screens or game states).
            _data->machine.processStateChanges();

            // Get the new current time in seconds.
            float newTime = _clock.getElapsedTime().asSeconds();
            // Calculate the time passed since the last frame was processed.
            float frameTime = newTime - currTime;
            // Clamp frame time to a maximum value to avoid spiral of death.
            if (frameTime > 0.25f) frameTime = 0.25f;
            // Update the current time to the new time.
            currTime = newTime;

            // Initialize the accumulator with the frame time.
            float accumulatedTime = frameTime;
            // Process the updates as long as the accumulated time is
            // greater than or equal to the fixed delta time.
            while (accumulatedTime >= _dt) {
                // Handle user input for the active state.
                _data->machine.getActiveState()->handleInput();
                // Update the game logic for the active state by the fixed timestep, `_dt`.
                _data->machine.getActiveState()->update(_dt);
                // Reduce the accumulator by the fixed timestep.
                accumulatedTime -= _dt;
            }

            // Calculate the interpolation factor for rendering.
            // Used to render objects smoothly between updates.
            float interpolation = accumulatedTime / _dt;
            // Draw the current state of the game to the window using the interpolation factor.
            _data->machine.getActiveState()->draw(interpolation);
        }
    }

}

/**
 *
 * `_dt = 1.f / 60.f` == fixed timestep interval for updates within the game loop,
 *                       calculated as the inverse of 60 frames per second (fps).
 *
 * This means each update step in your game is intended to simulate 1/60th of a second
 * or approximately 16.67 milliseconds. This is a common practice in game development
 * to ensure consistent logic processing regardless of frame rate variability.
 *
 * =========================
 * CONTEXT IN YOUR GAME LOOP
 * =========================
 *
 * 1. Fixed Time Step:
 * -------------------
 *  The value of _dt (approximately 0.01667 seconds) is used as a constant duration
 *  for which each game logic update is processed. This helps in maintaining consistent
 *  game behavior across different hardware, where rendering speeds might vary.
 *
 * 2. Accumulator Mechanism:
 * -------------------------
 *  The accumulator variable collects the time that has elapsed since the last frame was
 *  rendered. The loop while (accumulator >= _dt) ensures that the game updates are
 *  processed in fixed chunks of _dt. If the frame was rendered slower than expected,
 *  resulting in a larger frameTime, multiple updates might occur in a single frame to
 *  "catch up" and maintain game logic synchronization.
 *
 * 3. Smooth Gameplay:
 * -------------------
 *  By using a fixed timestep for updates (_dt), your game logic remains stable and
 *  predictable. It doesn't speed up or slow down based on the frame rate, which might
 *  fluctuate. This is crucial for physics calculations, animations, and other game
 *  mechanics that rely on consistent timing.
 *
 * 4. Interpolation for Rendering:
 * -------------------------------
 *  Since rendering might not align perfectly with these fixed updates (e.g., there
 *  might be leftover time in the accumulator after all possible updates are processed),
 *  the interpolation variable is calculated. This represents the ratio of the
 *  unprocessed time (accumulator) to _dt. This interpolation factor is used during
 *  rendering to smoothly display game objects in positions that reflect where they
 *  "should be" theoretically between updates.
 *
 *
 * ===========
 *   SUMMARY
 * ===========
 *
 * By defining `_dt = 1.f / 60.f`, you're aiming for a smooth and consistent gameplay experience
 * by ensuring that the game logic updates at a steady rate of 60 times per second, regardless of
 * the actual frame rate at which the game is rendered.
 *
 */