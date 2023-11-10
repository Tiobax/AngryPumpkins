#pragma once

#ifndef MovableGameObject_h
#define MovableGameObject_h

#include "GameObject.h"
#include "Direction.h"

class MovableGameObject : public GameObject
{
protected:
	float speed;
	Direction direction;
	sf::Texture textureUp;
	sf::Texture textureDown;
	sf::Texture textureLeft;
	sf::Texture textureRight;
	sf::SoundBuffer eatSoundBuffer;
	sf::Sound eatSound;

	void setTextureForSprite();
	bool calculateBoardCollision();
	virtual void changeDirection() = 0;
	virtual void handlingPumpkinCollision() = 0;
	virtual void handlingWallCollision() = 0;
	virtual void handlingBorderCollision() = 0;

public:
	MovableGameObject();
	void updateMovableObject(float deltaTime, class Game& game);
};

#endif 
