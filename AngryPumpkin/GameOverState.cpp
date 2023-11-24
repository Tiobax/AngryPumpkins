#include "GameOverState.h"
#include "State.h"
#include "GameStateFactory.h"

GameOverState::GameOverState()
{
	assert(gameOverSoundBuffer.loadFromFile(GameSettings::getResourcesPath() + "Death.wav"));
	gameOverSound.setBuffer(gameOverSoundBuffer);
	gameOverSound.play();

	gameOverText.setFont(font);
	gameOverText.setString("GAME OVER!");
	gameOverText.setCharacterSize(200);
	const sf::FloatRect rectGameOverText = gameOverText.getLocalBounds();
	gameOverText.setOrigin(rectGameOverText.width * 0.5f, rectGameOverText.height);
	gameOverText.setFillColor(sf::Color(19, 158, 198));
	gameOverText.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.5f);

	hintText.setFont(font);
	hintText.setString("press ESC to continue");
	hintText.setCharacterSize(50);
	const sf::FloatRect rectHintText = hintText.getLocalBounds();
	hintText.setOrigin(rectHintText.width * 0.5f, rectHintText.height);
	hintText.setFillColor(sf::Color(19, 158, 198));
	hintText.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.6f);
}

void GameOverState::update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		gameState = GameStateFactory::createGameState(State::MENU);
	}
}

void GameOverState::draw(sf::RenderWindow& window)
{
	window.draw(gameOverText);
	window.draw(hintText);
}
