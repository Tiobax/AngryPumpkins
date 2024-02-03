#pragma once
#include <SFML/Graphics.hpp>
#include "game_object.h"

class CalculationCollisions
{
public:
	static bool IsCollisionPressedMouseAndButton(sf::Vector2i mouse_position, sf::Text button);
	static bool IsCollisionMovableObjectAndObstacle(GameObject& object, GameObject& obstacle);
	static bool IsCollisionTwoObjects(GameObject& object_1, GameObject& object_2);
};