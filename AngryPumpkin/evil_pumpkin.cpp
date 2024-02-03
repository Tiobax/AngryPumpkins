#include "evil_pumpkin.h"

void EvilPumpkin::ChangeDirection()
{
	const int current_time = clock() / CLOCKS_PER_SEC;
	if (time_for_change_direction_ - current_time < 0)
	{
		SetDirection();
		SetTimeForChangeDirection();
	}
}

void EvilPumpkin::HandlingPumpkinCollision()
{
	IncreaseSpeed();
}

void EvilPumpkin::HandlingWallCollision()
{
	SetDirection();
}

void EvilPumpkin::HandlingBorderCollision()
{
	SetDirection();
}

void EvilPumpkin::SetDirection()
{
	const int random_direction = rand() % 2;
	if (direction_ == Direction::UP || direction_ == Direction::DOWN)
	{
		if (position_.x - GameSettings::get_objects_size() < 0)
		{
			direction_ = Direction::RIGHT;
		}
		else if (position_.x + GameSettings::get_objects_size() > GameSettings::get_screen_width())
		{
			direction_ = Direction::LEFT;
		}
		else
		{
			direction_ = random_direction == 0 ? Direction::RIGHT : Direction::LEFT;
		}
		direction_ = random_direction == 0 ? Direction::RIGHT : Direction::LEFT;
	}
	else
	{
		if (position_.y - GameSettings::get_objects_size() < GameSettings::get_up_board())
		{
			direction_ = Direction::DOWN;
		}
		else if (position_.y + GameSettings::get_objects_size() > GameSettings::get_screen_height())
		{
			direction_ = Direction::UP;
		}
		else
		{
			direction_ = random_direction == 0 ? Direction::UP : Direction::DOWN;
		}
		direction_ = random_direction == 0 ? Direction::UP : Direction::DOWN;
	}
}

EvilPumpkin::EvilPumpkin(sf::Vector2f position)
{
	assert(texture_up_.loadFromFile(kResourcesPath + "PumpkinUp.png"));
	assert(texture_down_.loadFromFile(kResourcesPath + "PumpkinDown.png"));
	assert(texture_right_.loadFromFile(kResourcesPath + "PumpkinRight.png"));
	assert(texture_left_.loadFromFile(kResourcesPath + "PumpkinLeft.png"));
	SetTextureForSprite();
	SetTimeForChangeDirection();
	InitSize();
	SetSpriteSize();
	SetSpriteRelativeOrigin();
	position_ = position;
	sprite_.setPosition(position_);
	CalculateCellNumbers();
}

void EvilPumpkin::SetTimeForChangeDirection()
{
	const int next_direction_time = 1 + rand() % 2;
	const int current_time = clock() / CLOCKS_PER_SEC;
	time_for_change_direction_ = (float)(current_time + next_direction_time);
}