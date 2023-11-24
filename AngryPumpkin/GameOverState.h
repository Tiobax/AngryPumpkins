#pragma once
#include "BaseState.h"

class GameOverState : public BaseState
{
public:
	GameOverState();
	void update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState) override;
	void draw(sf::RenderWindow& window) override;

protected:
	sf::Text gameOverText;
	sf::Text hintText;
	sf::SoundBuffer gameOverSoundBuffer;
	sf::Sound gameOverSound;
};