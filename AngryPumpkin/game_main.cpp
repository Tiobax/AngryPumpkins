// ©2023. All rights reserved.
// Authored by Evgeni Buko

#include "game_settings.h"
#include "base_state.h"
#include "game_state_factory.h"

int main()
{
	srand((int)time(nullptr));
	std::shared_ptr<BaseState> game_state = GameStateFactory::CreateGameState(State::MENU);
	sf::RenderWindow window(sf::VideoMode(GameSettings::get_screen_width(), GameSettings::get_screen_height()), "AngryPampkins");
	sf::Event event;

	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		game_state.get()->Update(window, game_state);
		game_state.get()->Draw(window);
		window.display();
	}

	return 0;
}
