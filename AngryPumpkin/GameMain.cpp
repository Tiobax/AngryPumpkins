// ©2023. All rights reserved.
// Authored by Evgeni Buko

#include "GameSettings.h"
#include "BaseState.h"
#include "GameStateFactory.h"

int main()
{
	srand((int)time(nullptr));
	std::shared_ptr<BaseState> gameState = GameStateFactory::createGameState(State::MENU);
	sf::RenderWindow window(sf::VideoMode(GameSettings::getScreenWidth(), GameSettings::getScreenHeight()), "AngryPampkins");
	sf::Event event;

	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		gameState.get()->update(window, gameState);
		gameState.get()->draw(window);
		window.display();
	}

	return 0;
}
