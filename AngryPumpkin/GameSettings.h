#pragma once
#include <SFML/Graphics.hpp>

class GameSettings
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
	static float getObjectsSize();
	static float getObjectsSpeed();
	static int getUpBoard();
	static bool getGameOverStatus();
	static void setGameOverStatus(bool status);
	static bool getWinStatus();
	static void setWinStatus(bool status);
	static bool getNumberOfPumpkinsSetting();
	static void changeNumberOfPumpkinsSetting();
	static int generateNumberOfPumpkins();
	static bool getAccelerationPlayerSetting();
	static void changeAccelerationPlayersSetting();
	static bool getNumberOfApplesForWinSetting();
	static void changeNumberOfApplesForWinSetting();
	static bool isWin();
	static int getPumpkinsCount();
	static std::string getResourcesPath();
	static std::string getScoreText();

private:
	static int screenWidth;
	static int screenHeight;
	static int upBoard;
	static int gameScore;
	static int evilPumpkinsCount;
	static int maxEvilPumpkins;
	static float objectSize;
	static float objectsSpeed;
	static sf::Vector2f waterSize;
	static bool gameOverStatus;
	static bool winStatus;
	static int gameSettings;
	static int winScore;
	static int pumpkinsCount;
	static std::string resourcesPath;
	static std::string scoreText;
};
