#pragma once

#include "GameObject.h"
#include "WaterType.h"

class Water : public GameObject
{
public:
	Water(WaterType walltype, sf::Vector2f _position);

private:
	void loadTexture(WaterType walltype);
	void initSize(WaterType walltype);
};
