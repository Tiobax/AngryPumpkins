#include "BaseState.h"

BaseState::BaseState()
{
	assert(font.loadFromFile(GameSettings::getResourcesPath() + "Fonts/HolliesWebs-Regular.ttf"));
	isLeftMouseButtonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left) ? true : false;
}
