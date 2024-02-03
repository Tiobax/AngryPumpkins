#pragma once
#include "base_state.h"

class MenuState : public BaseState
{
public:
	MenuState();
	void Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state) override;
	void Draw(sf::RenderWindow& window) override;

protected:
	sf::Texture logo_texture_;
	sf::Sprite logo_sprite_;
	sf::Text new_game_text_;
	sf::Text settings_text_;
	sf::Text score_text_;
	sf::Text exit_game_text_;
};