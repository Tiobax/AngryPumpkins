#include "Player.h"

void Player::changeDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = Direction::RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = Direction::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = Direction::LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = Direction::DOWN;
	}
}

void Player::handlingPumpkinCollision()
{
	eatSound.play();
	GameSettings::increaseGameScore();
	if (GameSettings::getNumberOfApplesForWinSetting() && GameSettings::isWin())
	{
		GameSettings::setWinStatus(true);
	}
	if (GameSettings::getAccelerationPlayerSetting()) {
		increaseSpeed();
	}
}

void Player::handlingWallCollision()
{
	GameSettings::setGameOverStatus(true);
}

void Player::handlingBorderCollision()
{
	GameSettings::setGameOverStatus(true);
}

Player::Player()
{
	assert(textureUp.loadFromFile(GameSettings::getResourcesPath() + "PlayerUp.png"));
	assert(textureDown.loadFromFile(GameSettings::getResourcesPath() + "PlayerDown.png"));
	assert(textureRight.loadFromFile(GameSettings::getResourcesPath() + "PlayerRight.png"));
	assert(textureLeft.loadFromFile(GameSettings::getResourcesPath() + "PlayerLeft.png"));
	setTextureForSprite();
	initSize();
	setSpriteSize();
	setSpriteRelativeOrigin();
	position = sf::Vector2f(GameSettings::getHalfGameScreenWidth(), GameSettings::getHalfGameScreenHeight());
	sprite.setPosition(position);
}