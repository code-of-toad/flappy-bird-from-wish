#pragma once

#include <memory>
#include <stack>
#include "State.hpp"

/**
 * Class Members w/ Built-in Types
 * -------------------------------
 * ...Are, by default, assigned garbage values.
 *
 * Therefore, you should ALWAYS assign them a default value as done below
 * for the three private `bool` members.
 */

/**
 * Class Members w/ Class Types (e.g., std::string)
 * ------------------------------------------------
 * ...Are default-constructed based on their class implementation.
 *
 * So, design your classes with their potential future, default behaviours in mind.
 */
namespace cot {

    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
        std::stack<StateRef> _states;
        StateRef             _newState;

        bool _isRemoving  = false;
        bool _isAdding    = false;
        bool _isReplacing = false;
    public:
        StateMachine()  = default;
        ~StateMachine() = default;

        void addState(StateRef newState, bool isReplacing=true);
        void removeState();

        void processStateChanges();
        StateRef& getActiveState();
    };

}