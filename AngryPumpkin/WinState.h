#pragma once
#include "BaseState.h"

class WinState : public BaseState
{
public:
	WinState();
	void update(sf::RenderWindow& window, std::shared_ptr<BaseState>& gameState) override;
	void draw(sf::RenderWindow& window) override;

protected:
	sf::Text winText;	
	sf::Text hintText;
	sf::SoundBuffer winSoundBuffer;
	sf::Sound winSound;
};