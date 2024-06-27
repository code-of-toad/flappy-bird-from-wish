#pragma once

/**
 * Pure Virtual Functions
 * ----------------------
 * Classes that contain at least one pure virtual function (declared via the ` = 0;`)
 * are abstract classes. THEY CANNOT BE INSTANTIATED DIRECTLY.
 *
 * Pure virtual functions are used to define an interface that derived classes must follow.
 */

/**
 * Optional Methods
 * ----------------
 * ...Allow derived classes to extend/customize behaviour without being forced
 * to implement every function.
 */
namespace cot {

    class State {
    public:
        // Virtual destructor for proper cleanup of derived classes.
        //     --> Ensures that derived class destructors are called properly
        //         when a pointer to the base class is deleted.
        virtual ~State() = default;

        // Pure virtual functions that derived states must implement.
        virtual void init()         = 0;
        virtual void handleInput()  = 0;
        virtual void update()       = 0;
        virtual void draw(float dt) = 0;

        // Optional methods that derived states can override.
        virtual void pause()  {}
        virtual void resume() {}

    };

}