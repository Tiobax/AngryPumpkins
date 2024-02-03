#include "player.h"

void Player::ChangeDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction_ = Direction::RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction_ = Direction::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction_ = Direction::LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction_ = Direction::DOWN;
	}
}

void Player::HandlingPumpkinCollision()
{
	eat_sound_.play();
	GameSettings::IncreaseGameScore();
	if (GameSettings::ReceiveNumberOfApplesForWinSetting() && GameSettings::IsWin())
	{
		GameSettings::set_win_status(true);
	}
	if (GameSettings::ReceiveAccelerationPlayerSetting()) {
		IncreaseSpeed();
	}
}

void Player::HandlingWallCollision()
{
	GameSettings::set_game_over_status(true);
}

void Player::HandlingBorderCollision()
{
	GameSettings::set_game_over_status(true);
}

Player::Player()
{
	assert(texture_up_.loadFromFile(kResourcesPath + "PlayerUp.png"));
	assert(texture_down_.loadFromFile(kResourcesPath + "PlayerDown.png"));
	assert(texture_right_.loadFromFile(kResourcesPath + "PlayerRight.png"));
	assert(texture_left_.loadFromFile(kResourcesPath + "PlayerLeft.png"));
	SetTextureForSprite();
	InitSize();
	SetSpriteSize();
	SetSpriteRelativeOrigin();
	position_ = sf::Vector2f(GameSettings::ReceiveHalfGameScreenWidth(), GameSettings::ReceiveHalfGameScreenHeight());
	sprite_.setPosition(position_);
	CalculateCellNumbers();
}