#pragma once
#include "base_state.h"


class ScoreState : public BaseState
{
public:
	ScoreState();
	void Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state) override;
	void Draw(sf::RenderWindow& window) override;

protected:
	sf::Text title_text_;
	sf::Text rank_title_text_;
	sf::Text name_title_text_;
	sf::Text score_title_text_;
	sf::Text score_back_text_;
	std::vector<std::vector<sf::Text>> score_text_;
};