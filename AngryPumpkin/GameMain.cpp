// ©2023. All rights reserved.
// Authored by Evgeni Buko

#include "GameState.h"
#include "Game.h"

int main()
{
	srand((int)time(nullptr));
	sf::RenderWindow window(sf::VideoMode(GameState::getScreenWidth(), GameState::getScreenHeight()), "AngryPampkins");
	sf::Event event;
	Game game;

	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		switch (game.getState())
		{
		case State::MENU:
			game.updateMenu(window);
			game.drawMenu(window);
			break;
		case State::GAME:
			game.updateGame();
			game.drawGame(window);
			break;
		case State::GAME_OVER:
			game.updateGameOver();
			game.drawGameOver(window);
			break;
		}
		window.display();
	}

	return 0;
}
