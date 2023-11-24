#pragma once

#include "MovableGameObject.h"
#include <ctime>

class EvilPumpkin : public MovableGameObject
{
public:
	EvilPumpkin(sf::Vector2f _position);
	void setTimeForChangeDirection();

private:
	float timeForChangeDirection;

	void changeDirection() override;
	void handlingPumpkinCollision() override;
	void handlingWallCollision() override;
	void handlingBorderCollision() override;
	void setDirection();
};