#include "GameState.h"

int GameState::screenWidth = 2000;
int GameState::screenHeight = 1000;
int GameState::upBoard = 42; 
int GameState::gameScore = 0;
int GameState::evilPumpkinsCount = 0;
int GameState::maxEvilPumpkins = 10;
float GameState::objectSize = 50.f;
bool GameState::gameOverStatus = false;
sf::Vector2f GameState::wallSize = sf::Vector2f(100.f, 20.f);

int GameState::getScreenWidth()
{
	return screenWidth;
}

float GameState::getHalfGameScreenWidth()
{
	return screenWidth * 0.5f;
}

int GameState::getScreenHeight()
{
	return screenHeight;
}

float GameState::getHalfGameScreenHeight()
{
	return (screenHeight - upBoard) * 0.5f;
}

void GameState::increaseGameScore()
{
	gameScore++;
}

int GameState::getGameScore()
{
	return gameScore;
}

void GameState::resetGameScore()
{
	gameScore = 0;
}

void GameState::increaseEvilPumpkins()
{
	evilPumpkinsCount++;
}

int GameState::getEvilPumpkins()
{
	return evilPumpkinsCount;
}

void GameState::resetEvilPumpkins()
{
	evilPumpkinsCount = 0;
}

int GameState::getMaxEvilPumpkins()
{
	return maxEvilPumpkins;
}

float GameState::getObjectSize()
{
	return objectSize;
}

int GameState::getUpBoard()
{
	return upBoard;
}

bool GameState::getGameOverStatus()
{
	return gameOverStatus;
}

bool GameState::setGameOverStatus(bool status)
{
	return gameOverStatus = status;
}