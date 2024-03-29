#pragma once

#include "movable_game_object.h"

class Player : public MovableGameObject
{
public:
	Player();

private:
	void ChangeDirection() override;
	void HandlingPumpkinCollision() override;
	void HandlingWallCollision() override;
	void HandlingBorderCollision() override;
};