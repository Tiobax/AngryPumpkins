#pragma once

#include "game_object.h"
#include "Direction.h"

class MovableGameObject : public GameObject
{
public:
	MovableGameObject();
	void UpdateMovableObject(float delta_time, class GameState& game);

protected:
	float speed_;
	Direction direction_;
	sf::Texture texture_up_;
	sf::Texture texture_down_;
	sf::Texture texture_left_;
	sf::Texture texture_right_;
	sf::SoundBuffer eat_sound_buffer_;
	sf::Sound eat_sound_;

	void IncreaseSpeed();
	void SetTextureForSprite();
	bool CalculateBoardCollision();
	virtual void ChangeDirection() = 0;
	virtual void HandlingPumpkinCollision() = 0;
	virtual void HandlingWallCollision() = 0;
	virtual void HandlingBorderCollision() = 0;
};