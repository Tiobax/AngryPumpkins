#include "win_state.h"
#include "State.h"
#include "game_state_factory.h"

WinState::WinState()
{
	assert(win_sound_buffer_.loadFromFile(kResourcesPath + "Win.wav"));
	win_sound_.setBuffer(win_sound_buffer_);
	win_sound_.play();

	InitTextObject(win_text_, "WIN!", 200, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.4f), true);
	InitTextObject(hint_text_, "press ESC to continue", 50, sf::Color(19, 158, 198), sf::Vector2f(0.5f, 0.6f), true);
}

void WinState::Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game_state = GameStateFactory::CreateGameState(State::MENU);
	}
}

void WinState::Draw(sf::RenderWindow& window)
{
	window.draw(win_text_);
	window.draw(hint_text_);
}
