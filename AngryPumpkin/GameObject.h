#pragma once

#ifndef GameObject_h
#define GameObject_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameState.h"
#include <cassert>

class GameObject
{
protected:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture texture;
	sf::Sprite sprite;

	void setSpriteSize();
	void setSpriteRelativeOrigin();
	void initSize();
	
public:
	void update();
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _position);
	sf::Vector2f getSize();
};

#endif