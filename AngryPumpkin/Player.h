#pragma once

#include "MovableGameObject.h"

class Player : public MovableGameObject
{
public:
	Player();

private:
	void changeDirection() override;
	void handlingPumpkinCollision() override;
	void handlingWallCollision() override;
	void handlingBorderCollision() override;
};