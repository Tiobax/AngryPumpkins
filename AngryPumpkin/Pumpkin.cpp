#include "pumpkin.h"

Pumpkin::Pumpkin(sf::Vector2f position)
{
	assert(texture_.loadFromFile(kResourcesPath + "Pumpkin.png"));
	sprite_.setTexture(texture_);
	InitSize();
	SetSpriteSize();
	SetSpriteRelativeOrigin();
	position_ = position;
	sprite_.setPosition(position_);
	CalculateCellNumbers();
}