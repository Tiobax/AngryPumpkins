#include "Game.h"
#include "Pumpkin.h"
#include "Water.h"
#include "Player.h"
#include "EvilPumpkin.h"

bool Game::isCollision(sf::Vector2f newPosition)
{
	bool objectsCollision = false;
	float size = GameState::getObjectSize();

	for (auto& it : staticGameObjectsMap) {
		if (it.first == typeid(Pumpkin).name())
		{
			float dx = newPosition.x - it.second->getPosition().x;
			float dy = newPosition.y - it.second->getPosition().y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size + it.second->getSize().x) * 0.5f)
			{
				objectsCollision = true;
			}
		}
		if (it.first == typeid(Water).name())
		{
			sf::Vector2f wallPosition = it.second->getPosition();
			float halfWallSize_x = it.second->getSize().x * 0.5f;
			float halfWallSize_y = it.second->getSize().y * 0.5f;
			if (abs(wallPosition.y - newPosition.y) <= halfWallSize_y + size * 0.5f && abs(wallPosition.x - newPosition.x) <= halfWallSize_x + size * 0.5f)
			{
				objectsCollision = true;
			}
		}
	}

	for (auto& it : movableGameObjectsMap) {
		if (it.first == typeid(EvilPumpkin).name())
		{
			float dx = newPosition.x - it.second->getPosition().x;
			float dy = newPosition.y - it.second->getPosition().y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size + it.second->getSize().x) * 0.5f)
			{
				objectsCollision = true;
			}
		}
		if (it.first == typeid(Player).name())
		{
			float dx = newPosition.x - it.second->getPosition().x;
			float dy = newPosition.y - it.second->getPosition().y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size + it.second->getSize().x))
			{
				objectsCollision = true;
			}
		}
	}
	return objectsCollision;
}

Game::Game()
{
	assert(font.loadFromFile(RESOURCES_PATH + "Fonts/HolliesWebs-Regular.ttf"));
	assert(logoTexture.loadFromFile(RESOURCES_PATH + "logo.png"));
	assert(font.loadFromFile(RESOURCES_PATH + "Fonts/HolliesWebs-Regular.ttf"));
	assert(gameOverSoundBuffer.loadFromFile(RESOURCES_PATH + "Death.wav"));

	state = State::MENU;
	lastTime = 0;

	logoSprite.setTexture(logoTexture);
	sf::FloatRect spriteRect = logoSprite.getLocalBounds();
	float logoScale = GameState::getScreenWidth() * 0.8f / spriteRect.width;
	logoSprite.setScale(logoScale, logoScale);
	logoSprite.setOrigin(spriteRect.width * 0.5f, 0);
	logoSprite.setPosition(GameState::getScreenWidth() * 0.5f, GameState::getScreenHeight() * 0.1f);

	newGameText.setFont(font);
	newGameText.setString("NEW GAME");
	newGameText.setCharacterSize(100);
	sf::FloatRect rectNewGameText = newGameText.getLocalBounds();
	newGameText.setOrigin(rectNewGameText.width * 0.5f, rectNewGameText.height);
	newGameText.setFillColor(sf::Color(19, 158, 198));
	newGameText.setPosition(GameState::getScreenWidth() * 0.5f, GameState::getScreenHeight() * 0.75f);

	exitGameText.setFont(font);
	exitGameText.setString("EXIT");
	exitGameText.setCharacterSize(100);
	sf::FloatRect rectExitGameText = exitGameText.getLocalBounds();
	exitGameText.setOrigin(rectExitGameText.width * 0.5f, rectExitGameText.height);
	exitGameText.setFillColor(sf::Color(19, 158, 198));
	exitGameText.setPosition(GameState::getScreenWidth() * 0.5f, GameState::getScreenHeight() * 0.85f);

	scoreText.setFont(font);
	scoreText.setString(SCORE_TEXT + std::to_string(GameState::getGameScore()));
	scoreText.setCharacterSize(30);
	scoreText.setPosition(20.f, 0.f);

	dividingLine.setSize(sf::Vector2f(static_cast<float>(GameState::getScreenWidth()), 2));
	dividingLine.setOrigin(GameState::getHalfGameScreenWidth(), 2.f);
	dividingLine.setPosition(sf::Vector2f(GameState::getHalfGameScreenWidth(), 40.f));

	gameOverSound.setBuffer(gameOverSoundBuffer);

	gameOverText.setFont(font);
	gameOverText.setString("GAME OVER!");
	gameOverText.setCharacterSize(200);
	sf::FloatRect rectGameOverText = gameOverText.getLocalBounds();
	gameOverText.setOrigin(rectGameOverText.width * 0.5f, rectGameOverText.height);
	gameOverText.setFillColor(sf::Color(19, 158, 198));
	gameOverText.setPosition(GameState::getScreenWidth() * 0.5f, GameState::getScreenHeight() * 0.5f);

	hintText.setFont(font);
	hintText.setString("press ESC to continue");
	hintText.setCharacterSize(50);
	sf::FloatRect rectHintText = hintText.getLocalBounds();
	hintText.setOrigin(rectHintText.width * 0.5f, rectHintText.height);
	hintText.setFillColor(sf::Color(19, 158, 198));
	hintText.setPosition(GameState::getScreenWidth() * 0.5f, GameState::getScreenHeight() * 0.6f);
}

void Game::initMenu()
{
	state = State::MENU;
}

void Game::updateMenu(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		if (mousePosition.x >= newGameText.getPosition().x - newGameText.getLocalBounds().width * 0.5f && mousePosition.x <= newGameText.getPosition().x + newGameText.getLocalBounds().width * 0.5f
			&& mousePosition.y >= newGameText.getPosition().y - newGameText.getLocalBounds().height * 0.5f && mousePosition.y <= newGameText.getPosition().y + newGameText.getLocalBounds().height * 0.5f)
		{
			initGame();
		}
		else if (mousePosition.x >= exitGameText.getPosition().x - exitGameText.getLocalBounds().width * 0.5f && mousePosition.x <= exitGameText.getPosition().x + exitGameText.getLocalBounds().width * 0.5f
			&& mousePosition.y >= exitGameText.getPosition().y - exitGameText.getLocalBounds().height * 0.5f && mousePosition.y <= exitGameText.getPosition().y + exitGameText.getLocalBounds().height * 0.5f)
		{
			window.close();
		}
	}
}

void Game::drawMenu(sf::RenderWindow& window)
{
	window.draw(logoSprite);
	window.draw(newGameText);
	window.draw(exitGameText);
}

void Game::initGame()
{
	state = State::GAME;

	movableGameObjectsMap.clear();
	staticGameObjectsMap.clear();

	std::shared_ptr<MovableGameObject> player(new Player());
	movableGameObjectsMap.insert(make_pair(typeid(Player).name(), player));

	std::shared_ptr<GameObject> wall_1(new Water(WaterType::LONG, sf::Vector2f(GameState::getScreenWidth() * 0.25f, GameState::getUpBoard() + (GameState::getScreenHeight() - GameState::getUpBoard()) * 0.2f)));
	std::shared_ptr<GameObject> wall_2(new Water(WaterType::LONG, sf::Vector2f(GameState::getScreenWidth() * 0.75f, GameState::getUpBoard() + (GameState::getScreenHeight() - GameState::getUpBoard()) * 0.2f)));
	std::shared_ptr<GameObject> wall_3(new Water(WaterType::LONG, sf::Vector2f(GameState::getScreenWidth() * 0.25f, GameState::getUpBoard() + (GameState::getScreenHeight() - GameState::getUpBoard()) * 0.8f)));
	std::shared_ptr<GameObject> wall_4(new Water(WaterType::LONG, sf::Vector2f(GameState::getScreenWidth() * 0.75f, GameState::getUpBoard() + (GameState::getScreenHeight() - GameState::getUpBoard()) * 0.8f)));
	std::shared_ptr<GameObject> wall_5(new Water(WaterType::LAKE, sf::Vector2f(GameState::getScreenWidth() * 0.25f, GameState::getUpBoard() + (GameState::getScreenHeight() - GameState::getUpBoard()) * 0.5f)));
	std::shared_ptr<GameObject> wall_6(new Water(WaterType::LAKE, sf::Vector2f(GameState::getScreenWidth() * 0.75f, GameState::getUpBoard() + (GameState::getScreenHeight() - GameState::getUpBoard()) * 0.5f)));

	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), wall_1));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), wall_2));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), wall_3));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), wall_4));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), wall_5));
	staticGameObjectsMap.insert(make_pair(typeid(Water).name(), wall_6));

	for (size_t i = 0; i < PUMPKIN_COUNT; i++)
	{
		sf::Vector2f position = generateNewPosition();
		std::shared_ptr<GameObject> pumpkin(new Pumpkin(position));
		staticGameObjectsMap.insert(make_pair(typeid(Pumpkin).name(), pumpkin));
	}

	GameState::setGameOverStatus(false);
	GameState::resetGameScore();
	GameState::resetEvilPumpkins();
	lastTime = gameClock.getElapsedTime().asSeconds();
}

void Game::updateGame()
{
	float currentTime = gameClock.getElapsedTime().asSeconds();
	float deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	if (GameState::getEvilPumpkins() < GameState::getMaxEvilPumpkins() && GameState::getGameScore() / 5 > GameState::getEvilPumpkins())
	{
		GameState::increaseEvilPumpkins();
		sf::Vector2f position = generateNewPosition();
		std::shared_ptr<MovableGameObject> evilPumpkin(new EvilPumpkin(position));
		movableGameObjectsMap.insert(make_pair(typeid(EvilPumpkin).name(), evilPumpkin));
	}

	for (auto& it : movableGameObjectsMap) {
		it.second.get()->updateMovableObject(deltaTime, *this);
	}

	scoreText.setString(SCORE_TEXT + std::to_string(GameState::getGameScore()));

	if (GameState::getGameOverStatus()) {
		initGameOver();
	}
}

void Game::drawGame(sf::RenderWindow& window)
{
	window.draw(scoreText);
	window.draw(dividingLine);
	for (auto& it: movableGameObjectsMap) {
		it.second->draw(window);
	}
	for (auto & it: staticGameObjectsMap) {
		it.second->draw(window);
	}
}

void Game::initGameOver()
{
	state = State::GAME_OVER;
	gameOverSound.play();
}

void Game::updateGameOver()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		initMenu();
	}
}

void Game::drawGameOver(sf::RenderWindow& window)
{
	window.draw(gameOverText);
	window.draw(hintText);
}

State Game::getState()
{
	return state;
}

std::multimap<std::string, std::shared_ptr<MovableGameObject>> Game::getMovableGameObjectsMap()
{
	return movableGameObjectsMap;
}

std::multimap<std::string, std::shared_ptr<GameObject>> Game::getStaticGameObjectsMap()
{
	return staticGameObjectsMap;
}

sf::Vector2f Game::generateNewPosition()
{
	sf::Vector2f newPosition;
	float size = GameState::getObjectSize();
	do {
		newPosition.x = size * 0.5f + rand() % static_cast<int>(GameState::getScreenWidth() - size + 1);
		newPosition.y = GameState::getUpBoard() + size * 0.5f + rand() % static_cast<int>(GameState::getScreenHeight() - size - GameState::getUpBoard() + 1);
	} while (isCollision(newPosition));
	return newPosition;
}
