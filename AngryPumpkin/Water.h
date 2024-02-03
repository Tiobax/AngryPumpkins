#pragma once

#include "game_object.h"
#include "WaterType.h"

class Water : public GameObject
{
public:
	Water(WaterType water_type, sf::Vector2f position);

private:
	void LoadTexture(WaterType water_type);
	void InitSize(WaterType water_type);
};
