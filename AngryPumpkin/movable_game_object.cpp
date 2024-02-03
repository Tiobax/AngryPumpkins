#include "movable_game_object.h"
#include "player.h"
#include "game_state.h"
#include "calculation_collisions.h"

void MovableGameObject::IncreaseSpeed()
{
	speed_ += GameSettings::get_objects_speed() * 0.1f;
}

void MovableGameObject::SetTextureForSprite()
{
	switch (direction_)
	{
	case Direction::UP:
		sprite_.setTexture(texture_up_);
		break;
	case Direction::DOWN:
		sprite_.setTexture(texture_down_);
		break;
	case Direction::RIGHT:
		sprite_.setTexture(texture_right_);
		break;
	case Direction::LEFT:
		sprite_.setTexture(texture_left_);
		break;
	}
}

bool MovableGameObject::CalculateBoardCollision()
{
	if (position_.x - size_.x * 0.5f <= 0.f || position_.x + size_.x * 0.5f >= GameSettings::get_screen_width() ||
		position_.y - size_.y * 0.5f <= GameSettings::get_up_board() || position_.y + size_.y * 0.5f >= GameSettings::get_screen_height())
	{
		return true;
	}
	return false;
}

MovableGameObject::MovableGameObject()
{
	direction_ = Direction(rand() % 4);
	speed_ = GameSettings::get_objects_speed();
	assert(eat_sound_buffer_.loadFromFile(kResourcesPath + "Eat.wav"));
	eat_sound_.setBuffer(eat_sound_buffer_);
}


void MovableGameObject::UpdateMovableObject(float delta_time, GameState& game)
{
	ChangeDirection();

	switch (direction_)
	{
	case Direction::UP:
		sprite_.setTexture(texture_up_);
		position_.y -= speed_ * delta_time;
		break;
	case Direction::DOWN:
		sprite_.setTexture(texture_down_);
		position_.y += speed_ * delta_time;
		break;
	case Direction::RIGHT:
		sprite_.setTexture(texture_right_);
		position_.x += speed_ * delta_time;
		break;
	case Direction::LEFT:
		sprite_.setTexture(texture_left_);
		position_.x -= speed_ * delta_time;
		break;
	}

	CalculateCellNumbers();

	for (auto& it : game.get_obstacles())
	{
		if (CalculationCollisions::IsCollisionMovableObjectAndObstacle(*this, *it.get())) 
		{
			position_ = sprite_.getPosition();
			HandlingWallCollision();
		}
	}
	
	for (int cell : this->get_cell_numbers())
	{
		for (auto& it : game.get_pumpkins_set_by_key(cell))
		{
			if (CalculationCollisions::IsCollisionTwoObjects(*this, *it.get()))
			{
				HandlingPumpkinCollision();
				for (int position : it.get()->get_cell_numbers())
				{
					game.EraseElementFromPumpkinsGrid(position, it);
				}
				it->set_position(game.GenerateNewPosition());
				it->CalculateCellNumbers();
				for (int position : it.get()->get_cell_numbers())
				{
					game.InsertElementFromPumpkinsGrid(position, it);
				}
				it->Update();
			}
		}
	}

	if (typeid(*this) == typeid(Player))
	{
		for (auto& it : game.get_enemies())
		{
			if (CalculationCollisions::IsCollisionTwoObjects(*this, *it.get()))
			{
				GameSettings::set_game_over_status(true);
			}
		}
	}

	if (CalculateBoardCollision()) {
		position_ = sprite_.getPosition();
		HandlingBorderCollision();
	}

	sprite_.setPosition(position_);
}