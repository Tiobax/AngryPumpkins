#include "Water.h"

void Water::loadTexture(WaterType waterType)
{
	if (waterType == WaterType::LONG) {
		assert(texture.loadFromFile(RESOURCES_PATH + "LongWall.png"));
	}
	else
	{
		assert(texture.loadFromFile(RESOURCES_PATH + "Column.png"));
	}
}

void Water::initSize(WaterType waterType)
{

	if (waterType == WaterType::LONG) {
		size.x = GameState::getScreenWidth() * 0.25f;
		size.y = GameState::getScreenHeight() * 0.05f;
	}
	else
	{
		size.x = size.y = GameState::getScreenHeight() * 0.1f;
	}
}

Water::Water(WaterType waterType, sf::Vector2f _position)
{
	loadTexture(waterType);
	sprite.setTexture(texture);
	initSize(waterType);
	setSpriteSize();
	setSpriteRelativeOrigin();
	position = _position;
	sprite.setPosition(position);
}