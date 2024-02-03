#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "score.h"

class GameSettings
{
public:
	static void set_player_name(std::string player_name);
	static void set_game_over_status(bool game_over_status);
	static void set_win_status(bool win_status);

	static bool get_win_status();
	static bool get_game_over_status();
	static int get_screen_width();
	static int get_screen_height();
	static int get_up_board();
	static int get_game_score();
	static int get_evil_pumpkins_count();
	static int get_max_evil_pumpkins_count();
	static int get_pumpkins_count();
	static float get_objects_size();
	static float get_objects_speed();
	static std::string get_player_name();
	static std::vector<Score> get_score_vector();

	static void IncreaseGameScore();
	static void IncreaseEvilPumpkins();
	static void ResetGameScore();
	static void ResetEvilPumpkins();
	static void ChangeScoreForPlayer();
	static void ChangeNumberOfPumpkinsSetting();
	static void ChangeAccelerationPlayersSetting();
	static void ChangeNumberOfApplesForWinSetting();
	static bool ReceiveNumberOfPumpkinsSetting();
	static bool ReceiveAccelerationPlayerSetting();
	static bool ReceiveNumberOfApplesForWinSetting();
	static bool IsWin();
	static int GenerateNumberOfPumpkins();
	static float ReceiveHalfGameScreenWidth();
	static float ReceiveHalfGameScreenHeight();

private:
	static bool game_over_status_;
	static bool win_status_;
	static int screen_width_;
	static int screen_height_;
	static int up_board_;
	static int game_score_;
	static int evil_pumpkins_count_;
	static int max_evil_pumpkins_count_;
	static int game_settings_;
	static int win_score_;
	static int pumpkins_count_;
	static float objects_size_;
	static float objects_speed_;
	static std::string player_name_;
	static std::vector<Score> score_vector_;

	static std::vector<Score> GenerationScoreMap();
	static void SortScoreVector();
};
