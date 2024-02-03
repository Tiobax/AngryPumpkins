#pragma once
#include "base_state.h"
#include "movable_game_object.h"

class GameState : public BaseState
{
public:
	GameState();
	void Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state) override;
	void Draw(sf::RenderWindow& window) override;
	std::shared_ptr<MovableGameObject> get_player();
	std::vector<std::shared_ptr<MovableGameObject>> get_enemies();
	std::vector<std::shared_ptr<GameObject>> get_pumpkins();
	std::vector<std::shared_ptr<GameObject>> get_obstacles();
	std::map<int, std::set<std::shared_ptr<GameObject>>> get_pumpkins_grid();
	std::set<std::shared_ptr<GameObject>> get_pumpkins_set_by_key(int key);
	sf::Vector2f GenerateNewPosition();
	void EraseElementFromPumpkinsGrid(int key, std::shared_ptr<GameObject> element);
	void InsertElementFromPumpkinsGrid(int key, std::shared_ptr<GameObject> element);

protected:
	std::shared_ptr<MovableGameObject> player_;
	std::vector<std::shared_ptr<MovableGameObject>> enemies_;
	std::vector<std::shared_ptr<GameObject>> pumpkins_;
	std::vector<std::shared_ptr<GameObject>> obstacles_;
	std::map<int, std::set<std::shared_ptr<GameObject>>> pumpkins_grid_;
	float last_time_;
	sf::Clock game_clock_;
	sf::RectangleShape dividing_line_;
	sf::Text score_text_;

	bool IsCollision(sf::Vector2f new_position);
};