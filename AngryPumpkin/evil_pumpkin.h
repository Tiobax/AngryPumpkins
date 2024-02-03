#pragma once

#include "movable_game_object.h"
#include <ctime>

class EvilPumpkin : public MovableGameObject
{
public:
	EvilPumpkin(sf::Vector2f position);
	void SetTimeForChangeDirection();

private:
	float time_for_change_direction_;

	void ChangeDirection() override;
	void HandlingPumpkinCollision() override;
	void HandlingWallCollision() override;
	void HandlingBorderCollision() override;
	void SetDirection();
};