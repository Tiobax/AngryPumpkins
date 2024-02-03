#include "score_state.h"
#include "calculation_collisions.h"
#include "State.h"
#include "game_state_factory.h"

ScoreState::ScoreState()
{
	InitTextObject(title_text_, "Score", 100, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.1f), true);
	float yPosition = 0.22f;
	InitTextObject(rank_title_text_, "Rank", 50, sf::Color(19, 158, 198), sf::Vector2f(0.15f, yPosition), false);
	InitTextObject(name_title_text_, "Name", 50, sf::Color(19, 158, 198), sf::Vector2f(0.45f, yPosition), false);
	InitTextObject(score_title_text_, "Score", 50, sf::Color(19, 158, 198), sf::Vector2f(0.8f, yPosition), false);
	yPosition += 0.02f;
	int number = 1;
	for (auto& it : GameSettings::get_score_vector())
	{
		yPosition += 0.05f;
		sf::Text rank;
		InitTextObject(rank, std::to_string(number++) + "th", 50, it.get_name() == GameSettings::get_player_name() ? sf::Color(255, 105, 0) : sf::Color(19, 158, 198), sf::Vector2f(0.15f, yPosition), false);
		sf::Text name;
		InitTextObject(name, it.get_name(), 50, it.get_name() == GameSettings::get_player_name() ? sf::Color(255, 105, 0) : sf::Color(19, 158, 198), sf::Vector2f(0.45f, yPosition), false);
		sf::Text score;
		InitTextObject(score, std::to_string(it.get_score_value()), 50, it.get_name() == GameSettings::get_player_name() ? sf::Color(255, 105, 0) : sf::Color(19, 158, 198), sf::Vector2f(0.8f, yPosition), false);
		std::vector<sf::Text> row = { rank, name, score };
		score_text_.push_back(row);
	}
	InitTextObject(score_back_text_, "BACK", 100, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.85f), true);
}

void ScoreState::Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		is_left_mouse_button_pressed_ = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !is_left_mouse_button_pressed_)
	{
		is_left_mouse_button_pressed_ = true;
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

		if (CalculationCollisions::IsCollisionPressedMouseAndButton(mouse_position, score_back_text_))
		{
			game_state = GameStateFactory::CreateGameState(State::MENU);
		}
	}
}

void ScoreState::Draw(sf::RenderWindow& window)
{
	window.draw(title_text_);
	window.draw(rank_title_text_);
	window.draw(name_title_text_);
	window.draw(score_title_text_);
	for (int i = 0; i < 10 ; i++)
	{
		for (sf::Text column : score_text_[i])
		{
			window.draw(column);
		}
	}
	window.draw(score_back_text_);
}
