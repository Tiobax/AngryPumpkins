#include "EvilPumpkin.h"

void EvilPumpkin::changeDirection()
{
	int currentTime = clock() / CLOCKS_PER_SEC;
	if (timeForChangeDirection - currentTime < 0)
	{
		setDirection();
		setTimeForChangeDirection();
	}
}

void EvilPumpkin::handlingPumpkinCollision()
{
	increaseSpeed();
}

void EvilPumpkin::handlingWallCollision()
{
	setDirection();
}

void EvilPumpkin::handlingBorderCollision()
{
	setDirection();
}

void EvilPumpkin::increaseSpeed()
{
	speed += OBJECT_SPEED * 0.1f;
}

void EvilPumpkin::setDirection()
{
	int randomDirection = rand() % 2;
	if (direction == Direction::UP || direction == Direction::DOWN)
	{
		if (position.x - GameState::getObjectSize() < 0)
		{
			direction = Direction::RIGHT;
		}
		else if (position.x + GameState::getObjectSize() > GameState::getScreenWidth())
		{
			direction = Direction::LEFT;
		}
		else
		{
			direction = randomDirection == 0 ? Direction::RIGHT : Direction::LEFT;
		}
		direction = randomDirection == 0 ? Direction::RIGHT : Direction::LEFT;
	}
	else
	{
		if (position.y - GameState::getObjectSize() < GameState::getUpBoard())
		{
			direction = Direction::DOWN;
		}
		else if (position.y + GameState::getObjectSize() > GameState::getScreenHeight())
		{
			direction = Direction::UP;
		}
		else
		{
			direction = randomDirection == 0 ? Direction::UP : Direction::DOWN;
		}
		direction = randomDirection == 0 ? Direction::UP : Direction::DOWN;
	}
}

EvilPumpkin::EvilPumpkin(sf::Vector2f _position)
{
	assert(textureUp.loadFromFile(RESOURCES_PATH + "PumpkinUp.png"));
	assert(textureDown.loadFromFile(RESOURCES_PATH + "PumpkinDown.png"));
	assert(textureRight.loadFromFile(RESOURCES_PATH + "PumpkinRight.png"));
	assert(textureLeft.loadFromFile(RESOURCES_PATH + "PumpkinLeft.png"));
	setTextureForSprite();
	setTimeForChangeDirection();
	initSize();
	setSpriteSize();
	setSpriteRelativeOrigin();
	position = _position;
	sprite.setPosition(position);
}

void EvilPumpkin::setTimeForChangeDirection()
{
	int nextDirectionTime = 1 + rand() % 2;
	int currentTime = clock() / CLOCKS_PER_SEC;
	timeForChangeDirection = (float)(currentTime + nextDirectionTime);
}