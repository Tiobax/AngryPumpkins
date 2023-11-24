#include "CalculationCollisions.h"

bool CalculationCollisions::isCollisionPressedMouseAndMenuButton(sf::Vector2i mousePosition, sf::Text button)
{
	if (mousePosition.x >= button.getPosition().x - button.getLocalBounds().width * 0.5f && mousePosition.x <= button.getPosition().x + button.getLocalBounds().width * 0.5f
		&& mousePosition.y >= button.getPosition().y - button.getLocalBounds().height * 0.5f && mousePosition.y <= button.getPosition().y + button.getLocalBounds().height * 0.5f)
	{
		return true;
	}
    return false;
}

bool CalculationCollisions::isCollisionPressedMouseAndSettingsButton(sf::Vector2i mousePosition, sf::Text button)
{
	if (mousePosition.x >= button.getPosition().x && mousePosition.x <= button.getPosition().x + button.getLocalBounds().width
		&& mousePosition.y >= button.getPosition().y && mousePosition.y <= button.getPosition().y + button.getLocalBounds().height)
	{
		return true;
	}
	return false;
}
