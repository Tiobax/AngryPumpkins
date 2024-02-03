#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game_settings.h"
#include <cassert>
#include "constants.h"

class BaseState
{
public:
	BaseState();
	virtual void Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

protected:
	bool is_left_mouse_button_pressed_;
	sf::Font font_;

	void InitTextObject(sf::Text& object, std::string text, int size, sf::Color color, sf::Vector2f position, bool is_center_need);
	void InitCircleShape(sf::CircleShape& circle_shape, float radius, sf::Vector2f position);
};