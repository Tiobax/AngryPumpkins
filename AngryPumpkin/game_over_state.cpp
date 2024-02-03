#include "game_over_state.h"
#include "State.h"
#include "game_state_factory.h"

GameOverState::GameOverState()
{
	assert(game_over_sound_buffer_.loadFromFile(kResourcesPath + "Death.wav"));
	game_over_sound_.setBuffer(game_over_sound_buffer_);
	game_over_sound_.play();

	InitTextObject(game_over_text_, "GAME OVER!", 200, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.1f), true);

	float yPosition = 0.27f;
	InitTextObject(rank_title_text_, "Rank", 50, sf::Color(19, 158, 198), sf::Vector2f(0.37f, yPosition), false);
	InitTextObject(name_title_text_, "Name", 50, sf::Color(19, 158, 198), sf::Vector2f(0.48f, yPosition), false);
	InitTextObject(score_title_text_, "Score", 50, sf::Color(19, 158, 198), sf::Vector2f(0.63f, yPosition), false);
	yPosition += 0.02f;
	int number = 1;
	for (auto& it : GameSettings::get_score_vector())
	{
		yPosition += 0.05f;
		sf::Text rank;
		InitTextObject(rank, std::to_string(number++) + "th", 50, it.get_name() == GameSettings::get_player_name() ? sf::Color(255, 105, 0) : sf::Color(19, 158, 198), sf::Vector2f(0.37f, yPosition), false);
		sf::Text name;
		InitTextObject(name, it.get_name(), 50, it.get_name() == GameSettings::get_player_name() ? sf::Color(255, 105, 0) : sf::Color(19, 158, 198), sf::Vector2f(0.48f, yPosition), false);
		sf::Text score;
		InitTextObject(score, std::to_string(it.get_score_value()), 50, it.get_name() == GameSettings::get_player_name() ? sf::Color(255, 105, 0) : sf::Color(19, 158, 198), sf::Vector2f(0.63f, yPosition), false);
		std::vector<sf::Text> row = { rank, name, score };
		score_text_.push_back(row);
	}

	InitTextObject(hint_text_, "press ESC to continue", 50, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.9f), true);
}

void GameOverState::Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game_state = GameStateFactory::CreateGameState(State::MENU);
	}
}

void GameOverState::Draw(sf::RenderWindow& window)
{
	window.draw(game_over_text_);
	window.draw(rank_title_text_);
	window.draw(name_title_text_);
	window.draw(score_title_text_);
	for (int i = 0; i < 10; i++)
	{
		for (sf::Text column : score_text_[i])
		{
			window.draw(column);
		}
	}
	window.draw(hint_text_);
}
