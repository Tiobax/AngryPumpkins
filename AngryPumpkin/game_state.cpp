#include "game_state.h"
#include "pumpkin.h"
#include "water.h"
#include "player.h"
#include "evil_pumpkin.h"
#include "calculation_collisions.h"
#include "State.h"
#include "game_state_factory.h"

GameState::GameState()
{
	score_text_.setFont(font_);
	score_text_.setString(kScoreText + std::to_string(GameSettings::get_game_score()));
	score_text_.setCharacterSize(30);
	score_text_.setPosition(20.f, 0.f);

	dividing_line_.setSize(sf::Vector2f(static_cast<float>(GameSettings::get_screen_width()), 2));
	dividing_line_.setOrigin(GameSettings::ReceiveHalfGameScreenWidth(), 2.f);
	dividing_line_.setPosition(sf::Vector2f(GameSettings::ReceiveHalfGameScreenWidth(), 40.f));
	
	std::shared_ptr<MovableGameObject> player_1(new Player());
	player_ = player_1;

	std::shared_ptr<GameObject> water_1(new Water(WaterType::LONG, sf::Vector2f(GameSettings::get_screen_width() * 0.25f, GameSettings::get_up_board() + (GameSettings::get_screen_height() - GameSettings::get_up_board()) * 0.2f)));
	std::shared_ptr<GameObject> water_2(new Water(WaterType::LONG, sf::Vector2f(GameSettings::get_screen_width() * 0.75f, GameSettings::get_up_board() + (GameSettings::get_screen_height() - GameSettings::get_up_board()) * 0.2f)));
	std::shared_ptr<GameObject> water_3(new Water(WaterType::LONG, sf::Vector2f(GameSettings::get_screen_width() * 0.25f, GameSettings::get_up_board() + (GameSettings::get_screen_height() - GameSettings::get_up_board()) * 0.8f)));
	std::shared_ptr<GameObject> water_4(new Water(WaterType::LONG, sf::Vector2f(GameSettings::get_screen_width() * 0.75f, GameSettings::get_up_board() + (GameSettings::get_screen_height() - GameSettings::get_up_board()) * 0.8f)));
	std::shared_ptr<GameObject> water_5(new Water(WaterType::LAKE, sf::Vector2f(GameSettings::get_screen_width() * 0.25f, GameSettings::get_up_board() + (GameSettings::get_screen_height() - GameSettings::get_up_board()) * 0.5f)));
	std::shared_ptr<GameObject> water_6(new Water(WaterType::LAKE, sf::Vector2f(GameSettings::get_screen_width() * 0.75f, GameSettings::get_up_board() + (GameSettings::get_screen_height() - GameSettings::get_up_board()) * 0.5f)));

	obstacles_.reserve(6);
	obstacles_.push_back(water_1);
	obstacles_.push_back(water_2);
	obstacles_.push_back(water_3);
	obstacles_.push_back(water_4);
	obstacles_.push_back(water_5);
	obstacles_.push_back(water_6);

	const int pumpcins_count = GameSettings::ReceiveNumberOfPumpkinsSetting() ? GameSettings::GenerateNumberOfPumpkins() : GameSettings::get_pumpkins_count();
	for (size_t i = 0; i < 16; i++)
	{
		std::unordered_set<std::shared_ptr<GameObject>> set;
		pumpkins_grid_.insert(std::pair<int, std::unordered_set<std::shared_ptr<GameObject>>>(i, set));
	}

	for (size_t i = 0; i < pumpcins_count; i++)
	{
		const sf::Vector2f position = GenerateNewPosition();
		const std::shared_ptr<GameObject> pumpkin(new Pumpkin(position));
		for (int position : pumpkin.get()->get_cell_numbers())
		{
			pumpkins_grid_[position].insert(pumpkin);
		}
		pumpkins_.push_back(pumpkin);
	}

	GameSettings::set_game_over_status(false);
	GameSettings::set_win_status(false);
	GameSettings::ResetGameScore();
	GameSettings::ResetEvilPumpkins();
	last_time_ = game_clock_.getElapsedTime().asSeconds();
}

void GameState::Update(sf::RenderWindow& window, std::shared_ptr<BaseState>& game_state)
{
	const float current_time = game_clock_.getElapsedTime().asSeconds();
	const float delta_time = current_time - last_time_;
	last_time_ = current_time;

	if (GameSettings::get_evil_pumpkins_count() < GameSettings::get_max_evil_pumpkins_count() && GameSettings::get_game_score() / 5 > GameSettings::get_evil_pumpkins_count())
	{
		GameSettings::IncreaseEvilPumpkins();
		const sf::Vector2f position = GenerateNewPosition();
		const std::shared_ptr<MovableGameObject> evil_pumpkin(new EvilPumpkin(position));
		enemies_.push_back(evil_pumpkin);
	}

	player_->UpdateMovableObject(delta_time, *this);

	for (auto& it : enemies_)
	{
		it->UpdateMovableObject(delta_time, *this);
	}

	score_text_.setString(kScoreText + std::to_string(GameSettings::get_game_score()));

	if (GameSettings::get_game_over_status())
	{
		GameSettings::ChangeScoreForPlayer();
		game_state = GameStateFactory::CreateGameState(State::GAME_OVER);
	}

	if (GameSettings::get_win_status())
	{
		GameSettings::ChangeScoreForPlayer();
		game_state = GameStateFactory::CreateGameState(State::WIN);
	}
}

void GameState::Draw(sf::RenderWindow& window)
{
	window.draw(score_text_);
	window.draw(dividing_line_);
	player_->Draw(window);

	for (auto& it : enemies_)
	{
		it->Draw(window);
	}

	for (auto& it : pumpkins_)
	{
		it->Draw(window);
	}

	for (auto& it : obstacles_)
	{
		it->Draw(window);
	}
}

std::shared_ptr<MovableGameObject> GameState::get_player()
{
	return player_;
}

std::vector<std::shared_ptr<MovableGameObject>> GameState::get_enemies()
{
	return enemies_;
}

std::vector<std::shared_ptr<GameObject>> GameState::get_pumpkins()
{
	return pumpkins_;
}

std::vector<std::shared_ptr<GameObject>> GameState::get_obstacles()
{
	return obstacles_;
}

std::unordered_map<int, std::unordered_set<std::shared_ptr<GameObject>>> GameState::get_pumpkins_grid()
{
	return pumpkins_grid_;
}

std::unordered_set<std::shared_ptr<GameObject>> GameState::get_pumpkins_set_by_key(int key)
{
	return pumpkins_grid_.find(key)->second;
}

sf::Vector2f GameState::GenerateNewPosition()
{
	sf::Vector2f new_position;
	const float size = GameSettings::get_objects_size();
	do {
		new_position.x = size * 0.5f + rand() % static_cast<int>(GameSettings::get_screen_width() - size + 1);
		new_position.y = GameSettings::get_up_board() + size * 0.5f + rand() % static_cast<int>(GameSettings::get_screen_height() - size - GameSettings::get_up_board() + 1);
	} while (IsCollision(new_position));
	return new_position;
}

void GameState::EraseElementFromPumpkinsGrid(int key, std::shared_ptr<GameObject> element)
{
	pumpkins_grid_.find(key)->second.erase(element);
}

void GameState::InsertElementFromPumpkinsGrid(int key, std::shared_ptr<GameObject> element)
{
	pumpkins_grid_.find(key)->second.insert(element);
}

bool GameState::IsCollision(sf::Vector2f new_position)
{
	bool objects_collision = false;
	float size = GameSettings::get_objects_size();

	for (auto& it : obstacles_)
	{
		const sf::Vector2f water_position = it.get()->get_position();
		const float half_water_size_x = it.get()->get_size().x * 0.5f;
		const float half_water_size_y = it.get()->get_size().y * 0.5f;
		if (abs(water_position.y - new_position.y) <= half_water_size_y + size * 0.5f && abs(water_position.x - new_position.x) <= half_water_size_x + size * 0.5f)
		{
			objects_collision = true;
		}
	}

	for (auto& it : pumpkins_)
	{
		const float dx = new_position.x - it.get()->get_position().x;
		const float dy = new_position.y - it.get()->get_position().y;
		const float distance = sqrt(dx * dx + dy * dy);
		if (distance < (size + it.get()->get_size().x) * 0.5f)
		{
			objects_collision = true;
		}
	}

	for (auto& it : enemies_)
	{
		const float dx = new_position.x - it.get()->get_position().x;
		const float dy = new_position.y - it.get()->get_position().y;
		const float distance = sqrt(dx * dx + dy * dy);
		if (distance < (size + it.get()->get_size().x) * 0.5f)
		{
			objects_collision = true;
		}
	}


	const float dx = new_position.x - player_.get()->get_position().x;
	const float dy = new_position.y - player_.get()->get_position().y;
	const float distance = sqrt(dx * dx + dy * dy);
	if (distance < (size + player_.get()->get_size().x))
	{
		objects_collision = true;
	}
	
	return objects_collision;
}