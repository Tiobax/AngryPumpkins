#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game_settings.h"
#include <cassert>
#include "constants.h"

class GameObject
{
public:
	void set_position(sf::Vector2f position);

	sf::Vector2f get_position();
	sf::Vector2f get_size();
	std::set<int> get_cell_numbers();

	void Update();
	void Draw(sf::RenderWindow& window);
	void CalculateCellNumbers();

protected:
	sf::Vector2f position_;
	sf::Vector2f size_;
	sf::Texture texture_;
	sf::Sprite sprite_;
	std::set<int> cell_numbers_;

	void SetSpriteSize();
	void SetSpriteRelativeOrigin();
	void InitSize();
	int CalculateCell(float x, float y);
	int CalculateCoefficient(float percent);
};