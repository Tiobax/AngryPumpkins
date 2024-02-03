#include "settings_state.h"
#include "calculation_collisions.h"
#include "State.h"
#include "game_state_factory.h"

SettingsState::SettingsState()
{
	InitTextObject(number_of_pumpkins_text_, "NUMBER OF APPLES:", 50, sf::Color(19, 158, 198), sf::Vector2f(0.05f, 0.1f), false);
	InitTextObject(fixed_number_text_, "FIXED NUMBER (20)", 40, GameSettings::ReceiveNumberOfPumpkinsSetting() ? sf::Color(19, 158, 198) : sf::Color::White, sf::Vector2f(0.07f, 0.15f), false);
	InitCircleShape(fixed_number_shape_, 10.f, sf::Vector2f(0.05f, 0.15f));
	InitTextObject(random_number_text_, "RANDOM NUMBER (5 - 30)", 40, GameSettings::ReceiveNumberOfPumpkinsSetting() ? sf::Color::White : sf::Color(19, 158, 198), sf::Vector2f(0.07f, 0.2f), false);
	InitCircleShape(random_number_shape_, 10.f, sf::Vector2f(0.05f, 0.2f));
	InitTextObject(acceleration_player_text_, "ACCELERATION PLAYER:", 50, sf::Color(19, 158, 198), sf::Vector2f(0.05f, 0.3f), false);
	InitTextObject(acceleration_player_false_text_, "FALSE", 40, GameSettings::ReceiveAccelerationPlayerSetting() ? sf::Color(19, 158, 198) : sf::Color::White, sf::Vector2f(0.07f, 0.35f), false);
	InitCircleShape(acceleration_player_false_shape_, 10.f, sf::Vector2f(0.05f, 0.35f));
	InitTextObject(acceleration_player_true_text_, "TRUE", 40, GameSettings::ReceiveNumberOfPumpkinsSetting() ? sf::Color::White : sf::Color(19, 158, 198), sf::Vector2f(0.07f, 0.4f), false);
	InitCircleShape(acceleration_player_true_shape_, 10.f, sf::Vector2f(0.05f, 0.4f));
	InitTextObject(number_of_pumpkins_for_win_text_, "NUMBER OF PUMPKINS FOR WIN:", 50, sf::Color(19, 158, 198), sf::Vector2f(0.05f, 0.5f), false);
	InitTextObject(infinity_text_, "INFINITY", 40, GameSettings::ReceiveNumberOfApplesForWinSetting() ? sf::Color(19, 158, 198) : sf::Color::White, sf::Vector2f(0.07f, 0.55f), false);
	InitCircleShape(infinity_shape_, 10.f, sf::Vector2f(0.05f, 0.55f));
	InitTextObject(final_number_of_pumpkins_for_win_text_, "FINAL (50)", 40, GameSettings::ReceiveNumberOfApplesForWinSetting() ? sf::Color::White : sf::Color(19, 158, 198), sf::Vector2f(0.07f, 0.6f), false);
	InitCircleShape(final_number_of_pumpkins_for_win_shape_, 10.f, sf::Vector2f(0.05f, 0.6f));
	InitTextObject(settings_back_text_, "BACK", 100, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.85f), true);
}

void SettingsState::Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		is_left_mouse_button_pressed_ = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !is_left_mouse_button_pressed_)
	{
		is_left_mouse_button_pressed_ = true;
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

		if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, settings_back_text_))
		{
			game_state = GameStateFactory::CreateGameState(State::MENU);
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, fixed_number_text_) && GameSettings::ReceiveNumberOfPumpkinsSetting())
		{
			fixed_number_text_.setFillColor(sf::Color::White);
			random_number_text_.setFillColor(sf::Color(19, 158, 198));
			GameSettings::ChangeNumberOfPumpkinsSetting();
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, random_number_text_) && !GameSettings::ReceiveNumberOfPumpkinsSetting())
		{
			random_number_text_.setFillColor(sf::Color::White);
			fixed_number_text_.setFillColor(sf::Color(19, 158, 198));
			GameSettings::ChangeNumberOfPumpkinsSetting();
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, acceleration_player_false_text_) && GameSettings::ReceiveAccelerationPlayerSetting())
		{
			acceleration_player_false_text_.setFillColor(sf::Color::White);
			acceleration_player_true_text_.setFillColor(sf::Color(19, 158, 198));
			GameSettings::ChangeAccelerationPlayersSetting();
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, acceleration_player_true_text_) && !GameSettings::ReceiveAccelerationPlayerSetting())
		{
			acceleration_player_true_text_.setFillColor(sf::Color::White);
			acceleration_player_false_text_.setFillColor(sf::Color(19, 158, 198));
			GameSettings::ChangeAccelerationPlayersSetting();
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, infinity_text_) && GameSettings::ReceiveNumberOfApplesForWinSetting())
		{
			infinity_text_.setFillColor(sf::Color::White);
			final_number_of_pumpkins_for_win_text_.setFillColor(sf::Color(19, 158, 198));
			GameSettings::ChangeNumberOfApplesForWinSetting();
		}
		else if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, final_number_of_pumpkins_for_win_text_) && !GameSettings::ReceiveNumberOfApplesForWinSetting())
		{
			final_number_of_pumpkins_for_win_text_.setFillColor(sf::Color::White);
			infinity_text_.setFillColor(sf::Color(19, 158, 198));
			GameSettings::ChangeNumberOfApplesForWinSetting();
		}
	}
}

void SettingsState::Draw(sf::RenderWindow& window)
{
	window.draw(settings_back_text_);
	window.draw(number_of_pumpkins_text_);
	window.draw(fixed_number_text_);
	window.draw(random_number_text_);
	GameSettings::ReceiveNumberOfPumpkinsSetting() ? window.draw(random_number_shape_) : window.draw(fixed_number_shape_);
	window.draw(acceleration_player_text_);
	window.draw(acceleration_player_false_text_);
	window.draw(acceleration_player_true_text_);
	GameSettings::ReceiveAccelerationPlayerSetting() ? window.draw(acceleration_player_true_shape_) : window.draw(acceleration_player_false_shape_);
	window.draw(number_of_pumpkins_for_win_text_);
	window.draw(infinity_text_);
	window.draw(final_number_of_pumpkins_for_win_text_);
	GameSettings::ReceiveNumberOfApplesForWinSetting() ? window.draw(final_number_of_pumpkins_for_win_shape_) : window.draw(infinity_shape_);
}
