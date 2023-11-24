#include "SettingsState.h"
#include "CalculationCollisions.h"
#include "State.h"
#include "GameStateFactory.h"

SettingsState::SettingsState()
{
	settingsBackText.setFont(font);
	settingsBackText.setString("BACK");
	settingsBackText.setCharacterSize(100);
	const sf::FloatRect rectSettingsBackText = settingsBackText.getLocalBounds();
	settingsBackText.setOrigin(rectSettingsBackText.width * 0.5f, rectSettingsBackText.height);
	settingsBackText.setFillColor(sf::Color(19, 158, 198));
	settingsBackText.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.9f);

	numberOfPumpkinsText.setFont(font);
	numberOfPumpkinsText.setString("NUMBER OF APPLES:");
	numberOfPumpkinsText.setCharacterSize(50);
	const sf::FloatRect rectNumberOfApples = numberOfPumpkinsText.getLocalBounds();
	numberOfPumpkinsText.setOrigin(rectNumberOfApples.left, rectNumberOfApples.top);
	numberOfPumpkinsText.setFillColor(sf::Color(19, 158, 198));
	numberOfPumpkinsText.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.1f);

	fixedNumberText.setFont(font);
	fixedNumberText.setString("FIXED NUMBER (20)");
	fixedNumberText.setCharacterSize(40);
	const sf::FloatRect rectFixedNumber = fixedNumberText.getLocalBounds();
	fixedNumberText.setOrigin(rectFixedNumber.left, rectFixedNumber.top);
	GameSettings::getNumberOfPumpkinsSetting() ? fixedNumberText.setFillColor(sf::Color(19, 158, 198)) : fixedNumberText.setFillColor(sf::Color::White);
	fixedNumberText.setPosition(GameSettings::getScreenWidth() * 0.07f, GameSettings::getScreenHeight() * 0.15f);

	fixedNumberShape.setRadius(10);
	fixedNumberShape.setOrigin(fixedNumberShape.getLocalBounds().left, fixedNumberShape.getLocalBounds().top);
	fixedNumberShape.setFillColor(sf::Color::White);
	fixedNumberShape.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.15f);

	randomNumberText.setFont(font);
	randomNumberText.setString("RANDOM NUMBER (5 - 30)");
	randomNumberText.setCharacterSize(40);
	const sf::FloatRect rectRandomNumber = randomNumberText.getLocalBounds();
	randomNumberText.setOrigin(rectRandomNumber.left, rectRandomNumber.top);
	GameSettings::getNumberOfPumpkinsSetting() ? randomNumberText.setFillColor(sf::Color::White) : randomNumberText.setFillColor(sf::Color(19, 158, 198));
	randomNumberText.setPosition(GameSettings::getScreenWidth() * 0.07f, GameSettings::getScreenHeight() * 0.2f);

	randomNumberShape.setRadius(10);
	randomNumberShape.setOrigin(randomNumberShape.getLocalBounds().left, randomNumberShape.getLocalBounds().top);
	randomNumberShape.setFillColor(sf::Color::White);
	randomNumberShape.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.2f);

	accelerationPlayerText.setFont(font);
	accelerationPlayerText.setString("ACCELERATION PLAYER:");
	accelerationPlayerText.setCharacterSize(50);
	const sf::FloatRect rectAccelerationPlayerText = accelerationPlayerText.getLocalBounds();
	accelerationPlayerText.setOrigin(rectAccelerationPlayerText.left, rectAccelerationPlayerText.top);
	accelerationPlayerText.setFillColor(sf::Color(19, 158, 198));
	accelerationPlayerText.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.3f);

	accelerationPlayerFalseText.setFont(font);
	accelerationPlayerFalseText.setString("FALSE");
	accelerationPlayerFalseText.setCharacterSize(40);
	const sf::FloatRect rectAccelerationPlayerFalseText = accelerationPlayerFalseText.getLocalBounds();
	accelerationPlayerFalseText.setOrigin(rectAccelerationPlayerFalseText.left, rectAccelerationPlayerFalseText.top);
	GameSettings::getAccelerationPlayerSetting() ? accelerationPlayerFalseText.setFillColor(sf::Color(19, 158, 198)) : accelerationPlayerFalseText.setFillColor(sf::Color::White);
	accelerationPlayerFalseText.setPosition(GameSettings::getScreenWidth() * 0.07f, GameSettings::getScreenHeight() * 0.35f);

	accelerationPlayerFalseShape.setRadius(10);
	accelerationPlayerFalseShape.setOrigin(accelerationPlayerFalseShape.getLocalBounds().left, accelerationPlayerFalseShape.getLocalBounds().top);
	accelerationPlayerFalseShape.setFillColor(sf::Color::White);
	accelerationPlayerFalseShape.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.35f);

	accelerationPlayerTrueText.setFont(font);
	accelerationPlayerTrueText.setString("TRUE");
	accelerationPlayerTrueText.setCharacterSize(40);
	const sf::FloatRect rectAccelerationPlayerTrueText = accelerationPlayerTrueText.getLocalBounds();
	accelerationPlayerTrueText.setOrigin(rectAccelerationPlayerTrueText.left, rectAccelerationPlayerTrueText.top);
	GameSettings::getAccelerationPlayerSetting() ? accelerationPlayerTrueText.setFillColor(sf::Color::White) : accelerationPlayerTrueText.setFillColor(sf::Color(19, 158, 198));
	accelerationPlayerTrueText.setPosition(GameSettings::getScreenWidth() * 0.07f, GameSettings::getScreenHeight() * 0.4f);

	accelerationPlayerTrueShape.setRadius(10);
	accelerationPlayerTrueShape.setOrigin(accelerationPlayerTrueShape.getLocalBounds().left, accelerationPlayerTrueShape.getLocalBounds().top);
	accelerationPlayerTrueShape.setFillColor(sf::Color::White);
	accelerationPlayerTrueShape.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.4f);

	numberOfPumpkinsForWinText.setFont(font);
	numberOfPumpkinsForWinText.setString("NUMBER OF PUMPKINS FOR WIN:");
	numberOfPumpkinsForWinText.setCharacterSize(50);
	const sf::FloatRect rectNumberOfApplesForWinText = numberOfPumpkinsForWinText.getLocalBounds();
	numberOfPumpkinsForWinText.setOrigin(rectNumberOfApplesForWinText.left, rectNumberOfApplesForWinText.top);
	numberOfPumpkinsForWinText.setFillColor(sf::Color(19, 158, 198));
	numberOfPumpkinsForWinText.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.5f);

	infinityText.setFont(font);
	infinityText.setString("INFINITY");
	infinityText.setCharacterSize(40);
	const sf::FloatRect rectInfinityText = infinityText.getLocalBounds();
	infinityText.setOrigin(rectInfinityText.left, rectInfinityText.top);
	GameSettings::getNumberOfApplesForWinSetting() ? infinityText.setFillColor(sf::Color(19, 158, 198)) : infinityText.setFillColor(sf::Color::White);
	infinityText.setPosition(GameSettings::getScreenWidth() * 0.07f, GameSettings::getScreenHeight() * 0.55f);

	infinityShape.setRadius(10);
	infinityShape.setOrigin(infinityShape.getLocalBounds().left, infinityShape.getLocalBounds().top);
	infinityShape.setFillColor(sf::Color::White);
	infinityShape.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.55f);

	finalNumberOfPumpkinsForWinText.setFont(font);
	finalNumberOfPumpkinsForWinText.setString("FINAL (50)");
	finalNumberOfPumpkinsForWinText.setCharacterSize(40);
	const sf::FloatRect rectFinalNumberOfApplesForWinText = finalNumberOfPumpkinsForWinText.getLocalBounds();
	finalNumberOfPumpkinsForWinText.setOrigin(rectFinalNumberOfApplesForWinText.left, rectFinalNumberOfApplesForWinText.top);
	GameSettings::getNumberOfApplesForWinSetting() ? finalNumberOfPumpkinsForWinText.setFillColor(sf::Color::White) : finalNumberOfPumpkinsForWinText.setFillColor(sf::Color(19, 158, 198));
	finalNumberOfPumpkinsForWinText.setPosition(GameSettings::getScreenWidth() * 0.07f, GameSettings::getScreenHeight() * 0.6f);

	finalNumberOfPumpkinsForWinShape.setRadius(10);
	finalNumberOfPumpkinsForWinShape.setOrigin(finalNumberOfPumpkinsForWinShape.getLocalBounds().left, finalNumberOfPumpkinsForWinShape.getLocalBounds().top);
	finalNumberOfPumpkinsForWinShape.setFillColor(sf::Color::White);
	finalNumberOfPumpkinsForWinShape.setPosition(GameSettings::getScreenWidth() * 0.05f, GameSettings::getScreenHeight() * 0.6f);
}

void SettingsState::update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isLeftMouseButtonPressed = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isLeftMouseButtonPressed)
	{
		isLeftMouseButtonPressed = true;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		if (CalculationCollisions::isCollisionPressedMouseAndMenuButton(mousePosition, settingsBackText))
		{
			gameState = GameStateFactory::createGameState(State::MENU);
		}
		else if (CalculationCollisions::isCollisionPressedMouseAndSettingsButton(mousePosition, fixedNumberText) && GameSettings::getNumberOfPumpkinsSetting())
		{
			fixedNumberText.setFillColor(sf::Color::White);
			randomNumberText.setFillColor(sf::Color(19, 158, 198));
			GameSettings::changeNumberOfPumpkinsSetting();
		}
		else if (CalculationCollisions::isCollisionPressedMouseAndSettingsButton(mousePosition, randomNumberText) && !GameSettings::getNumberOfPumpkinsSetting())
		{
			randomNumberText.setFillColor(sf::Color::White);
			fixedNumberText.setFillColor(sf::Color(19, 158, 198));
			GameSettings::changeNumberOfPumpkinsSetting();
		}
		else if (CalculationCollisions::isCollisionPressedMouseAndSettingsButton(mousePosition, accelerationPlayerFalseText) && GameSettings::getAccelerationPlayerSetting())
		{
			accelerationPlayerFalseText.setFillColor(sf::Color::White);
			accelerationPlayerTrueText.setFillColor(sf::Color(19, 158, 198));
			GameSettings::changeAccelerationPlayersSetting();
		}
		else if (CalculationCollisions::isCollisionPressedMouseAndSettingsButton(mousePosition, accelerationPlayerTrueText) && !GameSettings::getAccelerationPlayerSetting())
		{
			accelerationPlayerTrueText.setFillColor(sf::Color::White);
			accelerationPlayerFalseText.setFillColor(sf::Color(19, 158, 198));
			GameSettings::changeAccelerationPlayersSetting();
		}
		else if (CalculationCollisions::isCollisionPressedMouseAndSettingsButton(mousePosition, infinityText) && GameSettings::getNumberOfApplesForWinSetting())
		{
			infinityText.setFillColor(sf::Color::White);
			finalNumberOfPumpkinsForWinText.setFillColor(sf::Color(19, 158, 198));
			GameSettings::changeNumberOfApplesForWinSetting();
		}
		else if (CalculationCollisions::isCollisionPressedMouseAndSettingsButton(mousePosition, finalNumberOfPumpkinsForWinText) && !GameSettings::getNumberOfApplesForWinSetting())
		{
			finalNumberOfPumpkinsForWinText.setFillColor(sf::Color::White);
			infinityText.setFillColor(sf::Color(19, 158, 198));
			GameSettings::changeNumberOfApplesForWinSetting();
		}
	}
}

void SettingsState::draw(sf::RenderWindow& window)
{
	window.draw(settingsBackText);
	window.draw(numberOfPumpkinsText);
	window.draw(fixedNumberText);
	window.draw(randomNumberText);
	GameSettings::getNumberOfPumpkinsSetting() ? window.draw(randomNumberShape) : window.draw(fixedNumberShape);
	window.draw(accelerationPlayerText);
	window.draw(accelerationPlayerFalseText);
	window.draw(accelerationPlayerTrueText);
	GameSettings::getAccelerationPlayerSetting() ? window.draw(accelerationPlayerTrueShape) : window.draw(accelerationPlayerFalseShape);
	window.draw(numberOfPumpkinsForWinText);
	window.draw(infinityText);
	window.draw(finalNumberOfPumpkinsForWinText);
	GameSettings::getNumberOfApplesForWinSetting() ? window.draw(finalNumberOfPumpkinsForWinShape) : window.draw(infinityShape);
}
