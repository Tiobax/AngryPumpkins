#pragma once
#include "BaseState.h"
#include "State.h"

class GameStateFactory
{
public:
	static std::shared_ptr<BaseState> createGameState(State state);
};