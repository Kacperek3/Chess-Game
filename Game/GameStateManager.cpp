#include "GameStateManager.h"

void GameStateManager::AddState(StateRef newState, bool isReplacing) {
    _isAdding = true;
    _isReplacing = isReplacing;
    _newState = std::move(newState);
}

void GameStateManager::RemoveState() {
    _isRemoving = true;
}

void GameStateManager::ProcessStateChanges() {
    if (_isRemoving && !_states.empty()) {
        _states.pop();
        if (!_states.empty()) {
            _states.top()->Resume();
        }
        _isRemoving = false;
    }

    if (_isAdding) {
        if (!_states.empty()) {
            if (_isReplacing) {
                _states.pop();
            } else {
                _states.top()->Pause();
            }
        }
        _states.push(std::move(_newState));
        _states.top()->Init();
        _isAdding = false;
    }
}

StateRef &GameStateManager::GetActiveState() {
    return _states.top();
}