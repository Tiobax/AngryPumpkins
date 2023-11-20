#pragma once

#include "MovableGameObject.h"
#include "State.h"

class Game
{
public:
	Game();
	void initMenu();
	void updateMenu(sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
	void initGame();
	void updateGame();
	void drawGame(sf::RenderWindow& window);
	void initGameOver();
	void updateGameOver();
	void drawGameOver(sf::RenderWindow& window);
	State getState();
	std::multimap<std::string, std::shared_ptr<MovableGameObject>> getMovableGameObjectsMap();
	std::multimap<std::string, std::shared_ptr<GameObject>> getStaticGameObjectsMap();
	sf::Vector2f generateNewPosition();

private:
	State state;
	sf::Font font;

	//Menu variables
	sf::Texture logoTexture;
	sf::Sprite logoSprite;
	sf::Text newGameText;
	sf::Text exitGameText;

	//Game variables
	std::multimap<std::string, std::shared_ptr<MovableGameObject>> movableGameObjectsMap;
	std::multimap<std::string, std::shared_ptr<GameObject>> staticGameObjectsMap;
	float lastTime;
	sf::Clock gameClock;
	sf::RectangleShape dividingLine;
	sf::Text scoreText;

	//GameOver variables
	sf::Text gameOverText;
	sf::Text hintText;
	sf::SoundBuffer gameOverSoundBuffer;
	sf::Sound gameOverSound;

	bool isCollision(sf::Vector2f newPosition);
};


