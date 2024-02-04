#pragma once
#include "base_state.h"

class WinState : public BaseState
{
public:
	WinState();
	void Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state) override;
	void Draw(sf::RenderWindow& window) override;

protected:
	sf::Text win_text_;	
	sf::Text menu_;
	sf::Text continue_;
	sf::Text rank_title_text_;
	sf::Text name_title_text_;
	sf::Text score_title_text_;
	std::vector<std::vector<sf::Text>> score_text_;
	sf::Sound win_sound_;
	sf::SoundBuffer win_sound_buffer_;
};