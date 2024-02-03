#include "calculation_collisions.h"

bool CalculationCollisions::IsCollisionPressedMouseAndButton(sf::Vector2i mouse_position, sf::Text button)
{
	if (mouse_position.x >= button.getPosition().x && mouse_position.x <= button.getPosition().x + button.getLocalBounds().width
		&& mouse_position.y >= button.getPosition().y && mouse_position.y <= button.getPosition().y + button.getLocalBounds().height)
	{
		return true;
	}
    return false;
}

bool CalculationCollisions::IsCollisionMovableObjectAndObstacle(GameObject& object, GameObject& obstacle)
{
	const sf::Vector2f waterPosition = obstacle.get_position();
	const float halfWaterSizeX = obstacle.get_size().x * 0.5f;
	const float halfWaterSizeY = obstacle.get_size().y * 0.5f;
	if (abs(waterPosition.y - object.get_position().y) <= halfWaterSizeY + object.get_size().y * 0.5f && abs(waterPosition.x - object.get_position().x) <= halfWaterSizeX + object.get_size().x * 0.5f)
	{
		return true;
	}
	return false;
}

bool CalculationCollisions::IsCollisionTwoObjects(GameObject& object_1, GameObject& object_2)
{
	const float dx = object_1.get_position().x - object_2.get_position().x;
	const float dy = object_1.get_position().y - object_2.get_position().y;
	const float distance = sqrt(dx * dx + dy * dy);
	if (distance < (object_1.get_size().x + object_2.get_size().x) * 0.5f)
	{
		return true;
	}
	return false;
}