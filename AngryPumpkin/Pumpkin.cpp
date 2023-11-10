#include "Pumpkin.h"

Pumpkin::Pumpkin(sf::Vector2f _position)
{
	assert(texture.loadFromFile(RESOURCES_PATH + "Pumpkin.png"));
	sprite.setTexture(texture);
	initSize();
	setSpriteSize();
	setSpriteRelativeOrigin();
	position = _position;
	sprite.setPosition(position);
}