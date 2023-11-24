#include "GameState.h"
#include "Pumpkin.h"
#include "Water.h"
#include "Player.h"
#include "EvilPumpkin.h"
#include "CalculationCollisions.h"
#include "State.h"
#include "GameStateFactory.h"

GameState::GameState()
{
	scoreText.setFont(font);
	scoreText.setString(GameSettings::getScoreText() + std::to_string(GameSettings::getGameScore()));
	scoreText.setCharacterSize(30);
	scoreText.setPosition(20.f, 0.f);

	dividingLine.setSize(sf::Vector2f(static_cast<float>(GameSettings::getScreenWidth()), 2));
	dividingLine.setOrigin(GameSettings::getHalfGameScreenWidth(), 2.f);
	dividingLine.setPosition(sf::Vector2f(GameSettings::getHalfGameScreenWidth(), 40.f));

	movableGameObjectsMap.clear();
	staticGameObjectsMap.clear();

	std::shared_ptr<MovableGameObject> player(new Player());
	movableGameObjectsMap.insert(make_pair(typeid(Player).name(), player));

	std::shared_ptr<GameObject> water1(new Water(WaterType::LONG, sf::Vector2f(GameSettings::getScreenWidth() * 0.25f, GameSettings::getUpBoard() + (GameSettings::getScreenHeight() - GameSettings::getUpBoard()) * 0.2f)));
	std::shared_ptr<GameObject> water2(new Water(WaterType::LONG, sf::Vector2f(GameSettings::getScreenWidth() * 0.75f, GameSettings::getUpBoard() + (GameSettings::getScreenHeight() - GameSettings::getUpBoard()) * 0.2f)));
	std::shared_ptr<GameObject> water3(new Water(WaterType::LONG, sf::Vector2f(GameSettings::getScreenWidth() * 0.25f, GameSettings::getUpBoard() + (GameSettings::getScreenHeight() - GameSettings::getUpBoard()) * 0.8f)));
	std::shared_ptr<GameObject> water4(new Water(WaterType::LONG, sf::Vector2f(GameSettings::getScreenWidth() * 0.75f, GameSettings::getUpBoard() + (GameSettings::getScreenHeight() - GameSettings::getUpBoard()) * 0.8f)));
	std::shared_ptr<GameObject> water5(new Water(WaterType::LAKE, sf::Vector2f(GameSettings::getScreenWidth() * 0.25f, GameSettings::getUpBoard() + (GameSettings::getScreenHeight() - GameSettings::getUpBoard()) * 0.5f)));
	std::shared_ptr<GameObject> water6(new Water(WaterType::LAKE, sf::Vector2f(GameSettings::getScreenWidth() * 0.75f, GameSettings::getUpBoard() + (GameSettings::getScreenHeight() - GameSettings::getUpBoard()) * 0.5f)));

	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), water1));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), water2));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), water3));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), water4));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), water5));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), water6));

	const int pumpcinsCount = GameSettings::getNumberOfPumpkinsSetting() ? GameSettings::generateNumberOfPumpkins() : GameSettings::getPumpkinsCount();
	for (size_t i = 0; i < pumpcinsCount; i++)
	{
		const sf::Vector2f position = generateNewPosition();
		const std::shared_ptr<GameObject> pumpkin(new Pumpkin(position));
		staticGameObjectsMap.insert(make_pair(typeid(Pumpkin).name(), pumpkin));
	}

	GameSettings::setGameOverStatus(false);
	GameSettings::setWinStatus(false);
	GameSettings::resetGameScore();
	GameSettings::resetEvilPumpkins();
	lastTime = gameClock.getElapsedTime().asSeconds();
}

void GameState::update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState)
{
	const float currentTime = gameClock.getElapsedTime().asSeconds();
	const float deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	if (GameSettings::getEvilPumpkins() < GameSettings::getMaxEvilPumpkins() && GameSettings::getGameScore() / 5 > GameSettings::getEvilPumpkins())
	{
		GameSettings::increaseEvilPumpkins();
		const sf::Vector2f position = generateNewPosition();
		const std::shared_ptr<MovableGameObject> evilPumpkin(new EvilPumpkin(position));
		movableGameObjectsMap.insert(make_pair(typeid(EvilPumpkin).name(), evilPumpkin));
	}

	for (auto& it : movableGameObjectsMap)
	{
		it.second.get()->updateMovableObject(deltaTime, *this);
	}

	scoreText.setString(GameSettings::getScoreText() + std::to_string(GameSettings::getGameScore()));

	if (GameSettings::getGameOverStatus())
	{
		gameState = GameStateFactory::createGameState(State::GAME_OVER);
	}

	if (GameSettings::getWinStatus())
	{
		gameState = GameStateFactory::createGameState(State::WIN);
	}
}

void GameState::draw(sf::RenderWindow& window)
{
	window.draw(scoreText);
	window.draw(dividingLine);
	for (auto& it : movableGameObjectsMap) {
		it.second->draw(window);
	}
	for (auto& it : staticGameObjectsMap) {
		it.second->draw(window);
	}
}

std::multimap<std::string, std::shared_ptr<MovableGameObject>> GameState::getMovableGameObjectsMap()
{
	return movableGameObjectsMap;
}

std::multimap<std::string, std::shared_ptr<GameObject>> GameState::getStaticGameObjectsMap()
{
	return staticGameObjectsMap;
}

sf::Vector2f GameState::generateNewPosition()
{
	sf::Vector2f newPosition;
	const float size = GameSettings::getObjectsSize();
	do {
		newPosition.x = size * 0.5f + rand() % static_cast<int>(GameSettings::getScreenWidth() - size + 1);
		newPosition.y = GameSettings::getUpBoard() + size * 0.5f + rand() % static_cast<int>(GameSettings::getScreenHeight() - size - GameSettings::getUpBoard() + 1);
	} while (isCollision(newPosition));
	return newPosition;
}

bool GameState::isCollision(sf::Vector2f newPosition)
{
	bool objectsCollision = false;
	float size = GameSettings::getObjectsSize();

	for (auto& it : staticGameObjectsMap) {
		if (it.first == typeid(Pumpkin).name())
		{
			const float dx = newPosition.x - it.second->getPosition().x;
			const float dy = newPosition.y - it.second->getPosition().y;
			const float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size + it.second->getSize().x) * 0.5f)
			{
				objectsCollision = true;
			}
		}
		if (it.first == typeid(Water).name())
		{
			const sf::Vector2f waterPosition = it.second->getPosition();
			const float halfWaterSizeX = it.second->getSize().x * 0.5f;
			const float halfWaterSizeY = it.second->getSize().y * 0.5f;
			if (abs(waterPosition.y - newPosition.y) <= halfWaterSizeY + size * 0.5f && abs(waterPosition.x - newPosition.x) <= halfWaterSizeX + size * 0.5f)
			{
				objectsCollision = true;
			}
		}
	}

	for (auto& it : movableGameObjectsMap) {
		if (it.first == typeid(EvilPumpkin).name())
		{
			const float dx = newPosition.x - it.second->getPosition().x;
			const float dy = newPosition.y - it.second->getPosition().y;
			const float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size + it.second->getSize().x) * 0.5f)
			{
				objectsCollision = true;
			}
		}
		if (it.first == typeid(Player).name())
		{
			const float dx = newPosition.x - it.second->getPosition().x;
			const float dy = newPosition.y - it.second->getPosition().y;
			const float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size + it.second->getSize().x))
			{
				objectsCollision = true;
			}
		}
	}
	return objectsCollision;
}
