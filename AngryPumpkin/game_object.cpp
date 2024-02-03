#include "game_object.h"

void GameObject::SetSpriteSize()
{
	const sf::FloatRect spriteRect = sprite_.getLocalBounds();
	const sf::Vector2f scale = { size_.x / spriteRect.width, size_.y / spriteRect.height };
	sprite_.setScale(scale);
}

void GameObject::SetSpriteRelativeOrigin()
{
	const sf::FloatRect spriteRect = sprite_.getLocalBounds();
	sprite_.setOrigin(spriteRect.width * 0.5f, spriteRect.height * 0.5f);
}

void GameObject::InitSize()
{
	size_ = sf::Vector2f(GameSettings::get_objects_size(), GameSettings::get_objects_size());
}

void GameObject::CalculateCellNumbers()
{
	cell_numbers_.clear();

	float point_left_x = (position_.x - size_.x * 0.5f) / GameSettings::get_screen_width();
	float point_right_x = (position_.x + size_.x * 0.5f) / GameSettings::get_screen_width();
	float point_top_y = (position_.y - size_.y * 0.5f) / GameSettings::get_screen_height();
	float point_down_y = (position_.y + size_.y * 0.5f) / GameSettings::get_screen_height();

	cell_numbers_.insert(CalculateCell(point_left_x, point_top_y));
	cell_numbers_.insert(CalculateCell(point_left_x, point_down_y));
	cell_numbers_.insert(CalculateCell(point_right_x, point_top_y));
	cell_numbers_.insert(CalculateCell(point_right_x, point_down_y));
}

int GameObject::CalculateCell(float x, float y)
{
	return 4 * CalculateCoefficient(y) + CalculateCoefficient(x);
}

int GameObject::CalculateCoefficient(float percent)
{
	if (0 <= percent and percent < 0.25) return 0;
	if (0.25 <= percent and percent < 0.5) return 1;
	if (0.5 <= percent and percent < 0.75) return 2;
	return 3;
} 

void GameObject::Update()
{
	sprite_.setPosition(position_);
}

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(sprite_);
}

void GameObject::set_position(sf::Vector2f position)
{
	position_ = position;
}

sf::Vector2f GameObject::get_size()
{
	return size_;
}

std::set<int> GameObject::get_cell_numbers()
{
	return cell_numbers_;
}

sf::Vector2f GameObject::get_position()
{
	return position_;
}


