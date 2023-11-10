#include "Water.h"

void Water::loadtexture(WaterType walltype)
{
	if (walltype == WaterType::LONG) {
		assert(texture.loadFromFile(RESOURCES_PATH + "LongWall.png"));
	}
	else
	{
		assert(texture.loadFromFile(RESOURCES_PATH + "Column.png"));
	}
}

void Water::initSize(WaterType walltype)
{

	if (walltype == WaterType::LONG) {
		size.x = GameState::getScreenWidth() * 0.25f;
		size.y = GameState::getScreenHeight() * 0.05f;
	}
	else
	{
		size.x = size.y = GameState::getScreenHeight() * 0.1f;
	}
}

Water::Water(WaterType walltype, sf::Vector2f _position)
{
	loadtexture(walltype);
	sprite.setTexture(texture);
	initSize(walltype);
	setSpriteSize();
	setSpriteRelativeOrigin();
	position = _position;
	sprite.setPosition(position);
}