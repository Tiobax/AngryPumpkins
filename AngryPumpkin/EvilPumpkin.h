#pragma once

#ifndef EvilPumpkin_h
#define EvilPumpkin_h

#include "MovableGameObject.h"
#include <ctime>

class EvilPumpkin : public MovableGameObject
{
private:
	float timeForChangeDirection;

	void changeDirection() override;
	void handlingPumpkinCollision() override;
	void handlingWallCollision() override;
	void handlingBorderCollision() override;
	void increaseSpeed();
	void setDirection();

public:
	EvilPumpkin(sf::Vector2f _position);
	void setTimeForChangeDirection();
};

#endif