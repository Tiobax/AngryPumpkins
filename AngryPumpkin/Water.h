#pragma once

#ifndef Water_h
#define Water_h

#include "GameObject.h"
#include "WaterType.h"

class Water : public GameObject
{
private:
	void loadtexture(WaterType walltype);
	void initSize(WaterType walltype);

public:
	Water(WaterType walltype, sf::Vector2f _position);
};

#endif 