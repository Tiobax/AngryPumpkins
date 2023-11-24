#pragma once
#include "BaseState.h"

class MenuState : public BaseState
{
public:
	MenuState();
	void update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState) override;
	void draw(sf::RenderWindow& window) override;

protected:
	sf::Texture logoTexture;
	sf::Sprite logoSprite;
	sf::Text newGameText;
	sf::Text settingsText;
	sf::Text exitGameText;
};