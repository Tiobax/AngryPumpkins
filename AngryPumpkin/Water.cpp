#include "water.h"

void Water::LoadTexture(WaterType water_type)
{
	if (water_type == WaterType::LONG) {
		assert(texture_.loadFromFile(kResourcesPath + "LongWall.png"));
	}
	else
	{
		assert(texture_.loadFromFile(kResourcesPath + "Column.png"));
	}
}

void Water::InitSize(WaterType water_type)
{

	if (water_type == WaterType::LONG) {
		size_.x = GameSettings::get_screen_width() * 0.25f;
		size_.y = GameSettings::get_screen_height() * 0.05f;
	}
	else
	{
		size_.x = size_.y = GameSettings::get_screen_height() * 0.1f;
	}
}

Water::Water(WaterType water_type, sf::Vector2f position)
{
	LoadTexture(water_type);
	sprite_.setTexture(texture_);
	InitSize(water_type);
	SetSpriteSize();
	SetSpriteRelativeOrigin();
	position_ = position;
	sprite_.setPosition(position_);
}