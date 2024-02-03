#include "menu_state.h"
#include "calculation_collisions.h"
#include "State.h"
#include "game_state_factory.h"

MenuState::MenuState()
{
	assert(logo_texture_.loadFromFile(kResourcesPath + "logo.png"));

	logo_sprite_.setTexture(logo_texture_);
	sf::FloatRect spriteRect = logo_sprite_.getLocalBounds();
	const float logoScale = GameSettings::get_screen_width() * 0.8f / spriteRect.width;
	logo_sprite_.setScale(logoScale, logoScale);
	logo_sprite_.setOrigin(spriteRect.width * 0.5f, 0);
	logo_sprite_.setPosition(GameSettings::get_screen_width() * 0.5f, GameSettings::get_screen_height() * 0.1f);

	InitTextObject(new_game_text_, "NEW GAME", 80, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.65f), true);
	InitTextObject(settings_text_, "SETTINGS", 80, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.73f), true);
	InitTextObject(score_text_, "SCORE", 80, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.81f), true);
	InitTextObject(exit_game_text_, "EXIT", 80, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.89f), true);
}

void MenuState::Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		is_left_mouse_button_pressed_ = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and !is_left_mouse_button_pressed_)
	{
		is_left_mouse_button_pressed_ = true;
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

		if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, new_game_text_))
		{
			game_state = GameStateFactory::CreateGameState(State::GAME);
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, settings_text_))
		{
			game_state = GameStateFactory::CreateGameState(State::SETTINGS);
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, score_text_))
		{
			game_state = GameStateFactory::CreateGameState(State::SCORE);
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, exit_game_text_))
		{
			window.close();
		}
	}
}

void MenuState::Draw(sf::RenderWindow& window)
{
	window.draw(logo_sprite_);
	window.draw(new_game_text_);
	window.draw(settings_text_);
	window.draw(score_text_);
	window.draw(exit_game_text_);
}
