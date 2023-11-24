#pragma once
#include "BaseState.h"
#include "MovableGameObject.h"

class GameState : public BaseState
{
public:
	GameState();
	void update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState) override;
	void draw(sf::RenderWindow& window) override;
	std::multimap<std::string, std::shared_ptr<MovableGameObject>> getMovableGameObjectsMap();
	std::multimap<std::string, std::shared_ptr<GameObject>> getStaticGameObjectsMap();
	sf::Vector2f generateNewPosition();

protected:
	std::multimap<std::string, std::shared_ptr<MovableGameObject>> movableGameObjectsMap;
	std::multimap<std::string, std::shared_ptr<GameObject>> staticGameObjectsMap;
	float lastTime;
	sf::Clock gameClock;
	sf::RectangleShape dividingLine;
	sf::Text scoreText;

	bool isCollision(sf::Vector2f newPosition);
};