#pragma once

#include "GameObject.h"
#include "Direction.h"

class MovableGameObject : public GameObject
{
public:
	MovableGameObject();
	void updateMovableObject(float deltaTime, class Game& game);

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
};