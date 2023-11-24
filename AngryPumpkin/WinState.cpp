#include "WinState.h"
#include "State.h"
#include "GameStateFactory.h"

WinState::WinState()
{
	assert(winSoundBuffer.loadFromFile(GameSettings::getResourcesPath() + "Win.wav"));
	winSound.setBuffer(winSoundBuffer);
	winSound.play();

	winText.setFont(font);
	winText.setString("WIN!");
	winText.setCharacterSize(200);
	const sf::FloatRect rectWinText = winText.getLocalBounds();
	winText.setOrigin(rectWinText.width * 0.5f, rectWinText.height);
	winText.setFillColor(sf::Color(19, 158, 198));
	winText.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.5f);

	hintText.setFont(font);
	hintText.setString("press ESC to continue");
	hintText.setCharacterSize(50);
	const sf::FloatRect rectHintText = hintText.getLocalBounds();
	hintText.setOrigin(rectHintText.width * 0.5f, rectHintText.height);
	hintText.setFillColor(sf::Color(19, 158, 198));
	hintText.setPosition(GameSettings::getScreenWidth() * 0.5f, GameSettings::getScreenHeight() * 0.6f);
}

void WinState::update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		gameState = GameStateFactory::createGameState(State::MENU);
	}
}

void WinState::draw(sf::RenderWindow& window)
{
	window.draw(winText);
	window.draw(hintText);
}
