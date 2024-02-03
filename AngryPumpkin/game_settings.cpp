#include "game_settings.h"
#include "GameSettingsBits.h"
#include "constants.h"

bool GameSettings::game_over_status_ = false;
bool GameSettings::win_status_ = false;
int GameSettings::screen_width_ = 2000;
int GameSettings::screen_height_ = 1000;
int GameSettings::up_board_ = 42; 
int GameSettings::game_score_ = 0;
int GameSettings::evil_pumpkins_count_ = 0;
int GameSettings::max_evil_pumpkins_count_ = 10;
int GameSettings::game_settings_ = 0;
int GameSettings::win_score_ = 50;
int GameSettings::pumpkins_count_ = 20;
float GameSettings::objects_size_ = 50.f;
float GameSettings::objects_speed_ = 200.f;
std::string GameSettings::player_name_ = "Player";
std::vector<Score> GameSettings::score_vector_ = GenerationScoreMap();

int GameSettings::get_screen_width()
{
	return screen_width_;
}

float GameSettings::ReceiveHalfGameScreenWidth()
{
	return screen_width_ * 0.5f;
}

int GameSettings::get_screen_height()
{
	return screen_height_;
}

float GameSettings::ReceiveHalfGameScreenHeight()
{
	return (screen_height_ - up_board_) * 0.5f;
}

void GameSettings::IncreaseGameScore()
{
	game_score_++;
}

int GameSettings::get_game_score()
{
	return game_score_;
}

void GameSettings::ResetGameScore()
{
	game_score_ = 0;
}

void GameSettings::IncreaseEvilPumpkins()
{
	evil_pumpkins_count_++;
}

int GameSettings::get_evil_pumpkins_count()
{
	return evil_pumpkins_count_;
}

void GameSettings::ResetEvilPumpkins()
{
	evil_pumpkins_count_ = 0;
}

int GameSettings::get_max_evil_pumpkins_count()
{
	return max_evil_pumpkins_count_;
}

float GameSettings::get_objects_size()
{
	return objects_size_;
}

float GameSettings::get_objects_speed()
{
	return objects_speed_;
}

int GameSettings::get_up_board()
{
	return up_board_;
}

bool GameSettings::get_game_over_status()
{
	return game_over_status_;
}

void GameSettings::set_game_over_status(bool game_over_status)
{
	game_over_status_ = game_over_status;
}

bool GameSettings::get_win_status()
{
	return win_status_;
}

void GameSettings::set_win_status(bool win_status)
{
	win_status_ = win_status;
}

bool GameSettings::ReceiveNumberOfPumpkinsSetting()
{
	return game_settings_ & static_cast<int>(GameSettingsBits::NUMBER_OF_PUMPKINS);
}

void GameSettings::ChangeNumberOfPumpkinsSetting()
{
	game_settings_ = game_settings_ ^ static_cast<int>(GameSettingsBits::NUMBER_OF_PUMPKINS);
}

int GameSettings::GenerateNumberOfPumpkins()
{
	return rand() % 26 + 5;
}

bool GameSettings::ReceiveAccelerationPlayerSetting()
{
	return game_settings_ & static_cast<int>(GameSettingsBits::ACCELERATION);
}

void GameSettings::ChangeAccelerationPlayersSetting()
{
	game_settings_ = game_settings_ ^ static_cast<int>(GameSettingsBits::ACCELERATION);
}

bool GameSettings::ReceiveNumberOfApplesForWinSetting()
{
	return game_settings_ & static_cast<int>(GameSettingsBits::NUMBER_OF_PUMPKINS_FOR_WIN);
}

void GameSettings::ChangeNumberOfApplesForWinSetting()
{
	game_settings_ = game_settings_ ^ static_cast<int>(GameSettingsBits::NUMBER_OF_PUMPKINS_FOR_WIN);
}

bool GameSettings::IsWin()
{
	return game_score_ >= win_score_ ? true : false;
}

int GameSettings::get_pumpkins_count()
{
	return pumpkins_count_;
}

std::string GameSettings::get_player_name()
{
	return player_name_;
}

void GameSettings::set_player_name(std::string player_name)
{
	player_name_ = player_name;
}

std::vector<Score> GameSettings::get_score_vector()
{
	SortScoreVector();
	return score_vector_;
}

std::vector<Score> GameSettings::GenerationScoreMap()
{
	srand((int)time(nullptr));
	std::vector<Score> score_vector;
	for (std::string name : kScoreNames)
	{
		score_vector.push_back(Score(name, rand() % win_score_ + 1));
	}
	score_vector.push_back(Score(player_name_, 0));
	return score_vector;
}

void GameSettings::SortScoreVector()
{
	int j, i = 1;
	while (i < score_vector_.size())
	{
		j = i;
		while (j != 0 and score_vector_[j - 1].get_score_value() < score_vector_[j].get_score_value())
		{
			std::swap(score_vector_[j - 1], score_vector_[j]);
			j--;
		}
		i++;
	}
}

void GameSettings::ChangeScoreForPlayer()
{
	for (auto& it : score_vector_)
	{
		if (it.get_name() == player_name_)
		{
			if (game_score_ > it.get_score_value())
			{
				it.set_score_value(game_score_);
			}
			return;
		}
	}
}
