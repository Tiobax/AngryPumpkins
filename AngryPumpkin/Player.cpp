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
	GameState::increaseGameScore();
}

void Player::handlingWallCollision()
{
	GameState::setGameOverStatus(true);
}

void Player::handlingBorderCollision()
{
	GameState::setGameOverStatus(true);
}

Player::Player()
{
	assert(textureUp.loadFromFile(RESOURCES_PATH + "PlayerUp.png"));
	assert(textureDown.loadFromFile(RESOURCES_PATH + "PlayerDown.png"));
	assert(textureRight.loadFromFile(RESOURCES_PATH + "PlayerRight.png"));
	assert(textureLeft.loadFromFile(RESOURCES_PATH + "PlayerLeft.png"));
	setTextureForSprite();
	initSize();
	setSpriteSize();
	setSpriteRelativeOrigin();
	position = sf::Vector2f(GameState::getHalfGameScreenWidth(), GameState::getHalfGameScreenHeight());
	sprite.setPosition(position);
}