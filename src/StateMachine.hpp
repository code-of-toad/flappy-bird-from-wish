#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <memory>
#include <stack>
#include "State.hpp"

namespace ToadCode {

    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
        std::stack<StateRef> _states;
        StateRef             _newState;
        bool                 _isAdding{};
        bool                 _isRemoving{};
        bool                 _isReplacing{};
    public:
        StateMachine()  = default;
        ~StateMachine() = default;
        void      addState(StateRef newState, bool isReplacing=true);
        void      removeState();
        void      processStateChanges();
        StateRef& getActiveState();
    };

}

#endif //STATEMACHINE_HPP
