#pragma once
#include "base_state.h"
#include "State.h"

class GameStateFactory
{
public:
	static std::shared_ptr<BaseState> CreateGameState(State state);
};