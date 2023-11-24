#pragma once
#include <SFML/Graphics.hpp>

class CalculationCollisions
{
public:
	static bool isCollisionPressedMouseAndMenuButton(sf::Vector2i mousePosition, sf::Text button);
	static bool isCollisionPressedMouseAndSettingsButton(sf::Vector2i mousePosition, sf::Text button);
};