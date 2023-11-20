#include "GameObject.h"

void GameObject::setSpriteSize()
{
	const sf::FloatRect spriteRect = sprite.getLocalBounds();
	const sf::Vector2f scale = { size.x / spriteRect.width, size.y / spriteRect.height };
	sprite.setScale(scale);
}

void GameObject::setSpriteRelativeOrigin()
{
	const sf::FloatRect spriteRect = sprite.getLocalBounds();
	sprite.setOrigin(spriteRect.width * 0.5f, spriteRect.height * 0.5f);
}

void GameObject::initSize()
{
	size = sf::Vector2f(GameState::getObjectSize(), GameState::getObjectSize());
}

void GameObject::update()
{
	sprite.setPosition(position);
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void GameObject::setPosition(sf::Vector2f _position)
{
	position = _position;
}

sf::Vector2f GameObject::getSize()
{
	return size;
}

sf::Vector2f GameObject::getPosition()
{
	return position;
}


