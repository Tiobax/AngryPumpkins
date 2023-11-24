#include "EvilPumpkin.h"

void EvilPumpkin::changeDirection()
{
	const int currentTime = clock() / CLOCKS_PER_SEC;
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

void EvilPumpkin::setDirection()
{
	const int randomDirection = rand() % 2;
	if (direction == Direction::UP || direction == Direction::DOWN)
	{
		if (position.x - GameSettings::getObjectsSize() < 0)
		{
			direction = Direction::RIGHT;
		}
		else if (position.x + GameSettings::getObjectsSize() > GameSettings::getScreenWidth())
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
		if (position.y - GameSettings::getObjectsSize() < GameSettings::getUpBoard())
		{
			direction = Direction::DOWN;
		}
		else if (position.y + GameSettings::getObjectsSize() > GameSettings::getScreenHeight())
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
	assert(textureUp.loadFromFile(GameSettings::getResourcesPath() + "PumpkinUp.png"));
	assert(textureDown.loadFromFile(GameSettings::getResourcesPath() + "PumpkinDown.png"));
	assert(textureRight.loadFromFile(GameSettings::getResourcesPath() + "PumpkinRight.png"));
	assert(textureLeft.loadFromFile(GameSettings::getResourcesPath() + "PumpkinLeft.png"));
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
	const int nextDirectionTime = 1 + rand() % 2;
	const int currentTime = clock() / CLOCKS_PER_SEC;
	timeForChangeDirection = (float)(currentTime + nextDirectionTime);
}