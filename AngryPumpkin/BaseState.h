#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameSettings.h"
#include <cassert>

class BaseState
{
public:
	BaseState();
	virtual void update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

protected:
	bool isLeftMouseButtonPressed;
	sf::Font font;
};