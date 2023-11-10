#pragma once

#ifndef Player_h
#define Player_h

#include "MovableGameObject.h"

class Player : public MovableGameObject
{
private:
	void changeDirection() override;
	void handlingPumpkinCollision() override;
	void handlingWallCollision() override;
	void handlingBorderCollision() override;

public:
	Player();
};

#endif 
