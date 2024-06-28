#include <iostream>
#include <cstdlib>
#include "StateMachine.hpp"

namespace cot {

    void StateMachine::addState(StateRef newState, const bool isReplacing) {
        _isAdding = true;
        _isReplacing = isReplacing;

        _newState = std::move(newState);
    }

    void StateMachine::removeState() {
        _isRemoving = true;
    }

    void StateMachine::processStateChanges() {
        if (_isRemoving && !_states.empty()) {
            _states.pop();
            if (!_states.empty()) {
                _states.top()->resume();
            }
            _isRemoving = false;
        }
        if (_isAdding) {
            if (!_states.empty()) {
                if (_isReplacing)
                    _states.pop();
                else
                    _states.top()->pause();
            }
            _states.push(std::move(_newState));
            _states.top()->init();
            _isAdding = false;
        }
    }

    StateRef& StateMachine::getActiveState() {
        // ERROR CHECK
        if (_states.empty()) {
            std::cerr << "StateMachine.cpp\n"
                      << "----------------\n"
                      << "cot::StateMachine::getActiveState()\n"
                      << ":\n+-> Can't call `.top()` on an empty std::stack.\n";
            exit(EXIT_FAILURE);
        }
        return _states.top();
    }

}