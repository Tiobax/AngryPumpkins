#include "GameSettings.h"
#include "GameSettingsBits.h"

bool GameSettings::gameOverStatus = false;
bool GameSettings::winStatus = false;
int GameSettings::screenWidth = 2000;
int GameSettings::screenHeight = 1000;
int GameSettings::upBoard = 42; 
int GameSettings::gameScore = 0;
int GameSettings::evilPumpkinsCount = 0;
int GameSettings::maxEvilPumpkins = 10;
int GameSettings::gameSettings = 0;
int GameSettings::winScore = 50;
int GameSettings::pumpkinsCount = 20;
float GameSettings::objectSize = 50.f;
float GameSettings::objectsSpeed = 200.f;
std::string GameSettings::resourcesPath = "Resources/";
std::string GameSettings::scoreText = "Score: ";

sf::Vector2f GameSettings::waterSize = sf::Vector2f(100.f, 20.f);

int GameSettings::getScreenWidth()
{
	return screenWidth;
}

float GameSettings::getHalfGameScreenWidth()
{
	return screenWidth * 0.5f;
}

int GameSettings::getScreenHeight()
{
	return screenHeight;
}

float GameSettings::getHalfGameScreenHeight()
{
	return (screenHeight - upBoard) * 0.5f;
}

void GameSettings::increaseGameScore()
{
	gameScore++;
}

int GameSettings::getGameScore()
{
	return gameScore;
}

void GameSettings::resetGameScore()
{
	gameScore = 0;
}

void GameSettings::increaseEvilPumpkins()
{
	evilPumpkinsCount++;
}

int GameSettings::getEvilPumpkins()
{
	return evilPumpkinsCount;
}

void GameSettings::resetEvilPumpkins()
{
	evilPumpkinsCount = 0;
}

int GameSettings::getMaxEvilPumpkins()
{
	return maxEvilPumpkins;
}

float GameSettings::getObjectsSize()
{
	return objectSize;
}

float GameSettings::getObjectsSpeed()
{
	return objectsSpeed;
}

int GameSettings::getUpBoard()
{
	return upBoard;
}

bool GameSettings::getGameOverStatus()
{
	return gameOverStatus;
}

void GameSettings::setGameOverStatus(bool status)
{
	gameOverStatus = status;
}

bool GameSettings::getWinStatus()
{
	return winStatus;
}

void GameSettings::setWinStatus(bool status)
{
	winStatus = status;
}

bool GameSettings::getNumberOfPumpkinsSetting()
{
	return gameSettings & static_cast<int>(GameSettingsBits::NUMBER_OF_PUMPKINS);
}

void GameSettings::changeNumberOfPumpkinsSetting()
{
	gameSettings = gameSettings ^ static_cast<int>(GameSettingsBits::NUMBER_OF_PUMPKINS);
}

int GameSettings::generateNumberOfPumpkins()
{
	return rand() % 26 + 5;
}

bool GameSettings::getAccelerationPlayerSetting()
{
	return gameSettings & static_cast<int>(GameSettingsBits::ACCELERATION);
}

void GameSettings::changeAccelerationPlayersSetting()
{
	gameSettings = gameSettings ^ static_cast<int>(GameSettingsBits::ACCELERATION);
}

bool GameSettings::getNumberOfApplesForWinSetting()
{
	return gameSettings & static_cast<int>(GameSettingsBits::NUMBER_OF_PUMPKINS_FOR_WIN);
}

void GameSettings::changeNumberOfApplesForWinSetting()
{
	gameSettings = gameSettings ^ static_cast<int>(GameSettingsBits::NUMBER_OF_PUMPKINS_FOR_WIN);
}

bool GameSettings::isWin()
{
	return gameScore >= winScore ? true : false;
}

int GameSettings::getPumpkinsCount()
{
	return pumpkinsCount;
}

std::string GameSettings::getResourcesPath()
{
	return resourcesPath;
}

std::string GameSettings::getScoreText()
{
	return scoreText;
}
