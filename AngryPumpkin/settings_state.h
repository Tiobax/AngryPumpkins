#pragma once
#include "base_state.h"

class SettingsState : public BaseState
{
public:
	SettingsState();
	void Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state) override;
	void Draw(sf::RenderWindow& window) override;

protected:
	sf::Text settings_back_text_;
	sf::Text number_of_pumpkins_text_;
	sf::Text fixed_number_text_;
	sf::Text random_number_text_;
	sf::Text acceleration_player_text_;
	sf::Text acceleration_player_false_text_;
	sf::Text acceleration_player_true_text_;
	sf::Text number_of_pumpkins_for_win_text_;
	sf::Text infinity_text_;
	sf::Text final_number_of_pumpkins_for_win_text_;
	sf::CircleShape fixed_number_shape_;
	sf::CircleShape random_number_shape_;
	sf::CircleShape acceleration_player_false_shape_;
	sf::CircleShape acceleration_player_true_shape_;
	sf::CircleShape infinity_shape_;
	sf::CircleShape final_number_of_pumpkins_for_win_shape_;
};