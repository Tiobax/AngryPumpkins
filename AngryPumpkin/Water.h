#pragma once

#include "GameObject.h"
#include "WaterType.h"

class Water : public GameObject
{
public:
	Water(WaterType waterType, sf::Vector2f _position);

private:
	void loadTexture(WaterType waterType);
	void initSize(WaterType waterType);
};
