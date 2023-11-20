#pragma once
#include <SFML/Graphics.hpp>

const std::string RESOURCES_PATH = "Resources/";
const int PUMPKIN_COUNT = 20;
const float OBJECT_SPEED = 200.f;
const std::string SCORE_TEXT = "Score: ";

class GameState
{
public:
	static int getScreenWidth();
	static float getHalfGameScreenWidth();
	static int getScreenHeight();
	static float getHalfGameScreenHeight();
	static void increaseGameScore();
	static int getGameScore();
	static void resetGameScore();
	static void increaseEvilPumpkins();
	static int getEvilPumpkins();
	static void resetEvilPumpkins();
	static int getMaxEvilPumpkins();
	static float getObjectSize();
	static int getUpBoard();
	static bool getGameOverStatus();
	static bool setGameOverStatus(bool status);

private:
	static int screenWidth;
	static int screenHeight;
	static int upBoard;
	static int gameScore;
	static int evilPumpkinsCount;
	static int maxEvilPumpkins;
	static float objectSize;
	static sf::Vector2f wallSize;
	static bool gameOverStatus;
};
