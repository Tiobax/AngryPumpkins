#include "base_state.h"
#include "constants.h"

BaseState::BaseState()
{
	assert(font_.loadFromFile(kResourcesPath + "Fonts/HolliesWebs-Regular.ttf"));
	is_left_mouse_button_pressed_ = sf::Mouse::isButtonPressed(sf::Mouse::Left) ? true : false;
}

void BaseState::InitTextObject(sf::Text& object, std::string text, int size, sf::Color color, sf::Vector2f position, bool is_center_need)
{
	object.setFont(font_);
	object.setString(text);
	object.setCharacterSize(size);
	const sf::FloatRect rect_win_text = object.getLocalBounds();
	object.setOrigin(rect_win_text.left, rect_win_text.top);
	object.setFillColor(color);
	const float position_x = is_center_need ? GameSettings::get_screen_width() * position.x - rect_win_text.width * 0.5f : GameSettings::get_screen_width() * position.x;
	const float position_y = GameSettings::get_screen_height() * position.y;
	object.setPosition(position_x, position_y);
}

void BaseState::InitCircleShape(sf::CircleShape& circle_shape, float radius, sf::Vector2f position)
{
	circle_shape.setRadius(radius);
	circle_shape.setOrigin(circle_shape.getLocalBounds().left, circle_shape.getLocalBounds().top);
	circle_shape.setFillColor(sf::Color::White);
	circle_shape.setPosition(GameSettings::get_screen_width() * position.x, GameSettings::get_screen_height() * position.y);
}
