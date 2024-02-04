#pragma once
#include "base_state.h"

class GameOverState : public BaseState
{
public:
	GameOverState();
	void Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state) override;
	void Draw(sf::RenderWindow& window) override;

protected:
	sf::Text game_over_text_;
	sf::Text menu_;
	sf::Text continue_;
	sf::Text rank_title_text_;
	sf::Text name_title_text_;
	sf::Text score_title_text_;
	std::vector<std::vector<sf::Text>> score_text_;
	sf::SoundBuffer game_over_sound_buffer_;
	sf::Sound game_over_sound_;
};