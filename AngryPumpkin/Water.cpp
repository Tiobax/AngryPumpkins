#include "Water.h"

void Water::loadTexture(WaterType waterType)
{
	if (waterType == WaterType::LONG) {
		assert(texture.loadFromFile(GameSettings::getResourcesPath() + "LongWall.png"));
	}
	else
	{
		assert(texture.loadFromFile(GameSettings::getResourcesPath() + "Column.png"));
	}
}

void Water::initSize(WaterType waterType)
{

	if (waterType == WaterType::LONG) {
		size.x = GameSettings::getScreenWidth() * 0.25f;
		size.y = GameSettings::getScreenHeight() * 0.05f;
	}
	else
	{
		size.x = size.y = GameSettings::getScreenHeight() * 0.1f;
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