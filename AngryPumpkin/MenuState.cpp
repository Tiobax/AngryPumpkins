#include "MenuState.h"
#include "CalculationCollisions.h"
#include "State.h"
#include "GameStateFactory.h"

MenuState::MenuState()
{
	assert(logoTexture.loadFromFile(GameSettings::getResourcesPath() + "logo.png"));

	logoSprite.setTexture(logoTexture);
	sf::FloatRect spriteRect = logoSprite.getLocalBounds();
	const float logoScale = GameSettings::getScreenWidth() * 0.8f / spriteRect.width;
	logoSprite.setScale(logoScale, logoScale);
	logoSprite.setOrigin(spriteRect.width * 0.5f, 0);
	logoSprite.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.1f);

	newGameText.setFont(font);
	newGameText.setString("NEW GAME");
	newGameText.setCharacterSize(100);
	const sf::FloatRect rectNewGameText = newGameText.getLocalBounds();
	newGameText.setOrigin(rectNewGameText.width * 0.5f, rectNewGameText.height);
	newGameText.setFillColor(sf::Color(19, 158, 198));
	newGameText.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.7f);

	settingsText.setFont(font);
	settingsText.setString("SETTINGS");
	settingsText.setCharacterSize(100);
	const sf::FloatRect rectSettingsText = settingsText.getLocalBounds();
	settingsText.setOrigin(rectSettingsText.width * 0.5f, rectSettingsText.height);
	settingsText.setFillColor(sf::Color(19, 158, 198));
	settingsText.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.8f);

	exitGameText.setFont(font);
	exitGameText.setString("EXIT");
	exitGameText.setCharacterSize(100);
	const sf::FloatRect rectExitGameText = exitGameText.getLocalBounds();
	exitGameText.setOrigin(rectExitGameText.width * 0.5f, rectExitGameText.height);
	exitGameText.setFillColor(sf::Color(19, 158, 198));
	exitGameText.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.9f);
}

void MenuState::update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isLeftMouseButtonPressed = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and !isLeftMouseButtonPressed)
	{
		isLeftMouseButtonPressed = true;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		if (CalculationCollisions::isCollisionPressedMouseAndMenuButton(mousePosition, newGameText))
		{
			gameState = GameStateFactory::createGameState(State::GAME);
		}
		else if (CalculationCollisions::isCollisionPressedMouseAndMenuButton(mousePosition, settingsText))
		{
			gameState = GameStateFactory::createGameState(State::SETTINGS);
		}
		else if (CalculationCollisions::isCollisionPressedMouseAndMenuButton(mousePosition, exitGameText))
		{
			window.close();
		}
	}
}

void MenuState::draw(sf::RenderWindow& window)
{
	window.draw(logoSprite);
	window.draw(newGameText);
	window.draw(settingsText);
	window.draw(exitGameText);
}
