#ifndef STATE_HPP
#define STATE_HPP

namespace ToadCode {
    class State {
    public:
        virtual ~State() = default;
        virtual void init()           = 0;
        virtual void handleInput()    = 0;
        virtual void update(float dt) = 0;
        virtual void draw(float dt)   = 0;  // `dt` is for framerate-independent gameplay
        virtual void pause()        {}
        virtual void resume()       {}
        // NOTE: The `= 0` syntax indicates that the function is "Pure Virtual".
        //       I.e., It MUST be implemented by any derived class.
    };
}

#endif // STATE_HPP