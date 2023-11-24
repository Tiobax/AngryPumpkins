#pragma once
#include "BaseState.h"

class SettingsState : public BaseState
{
public:
	SettingsState();
	void update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState) override;
	void draw(sf::RenderWindow& window) override;

protected:
	sf::Text settingsBackText;
	sf::Text numberOfPumpkinsText;
	sf::Text fixedNumberText;
	sf::CircleShape fixedNumberShape;
	sf::Text randomNumberText;
	sf::CircleShape randomNumberShape;
	sf::Text accelerationPlayerText;
	sf::Text accelerationPlayerFalseText;
	sf::CircleShape accelerationPlayerFalseShape;
	sf::Text accelerationPlayerTrueText;
	sf::CircleShape accelerationPlayerTrueShape;
	sf::Text numberOfPumpkinsForWinText;
	sf::Text infinityText;
	sf::CircleShape infinityShape;
	sf::Text finalNumberOfPumpkinsForWinText;
	sf::CircleShape finalNumberOfPumpkinsForWinShape;
};