#include "GameStateFactory.h"
#include "GameOverState.h"
#include "WinState.h"
#include "MenuState.h"
#include "SettingsState.h"
#include "GameState.h"

std::shared_ptr<BaseState> GameStateFactory::createGameState(State state)
{
    switch (state)
    {
    case State::MENU:
    {
        std::shared_ptr<BaseState> menuState(new MenuState());
        return menuState;
    }
    case State::SETTINGS:
    {
        std::shared_ptr<BaseState> settingsState(new SettingsState());
        return settingsState;
    }
    case State::GAME:
    {
        std::shared_ptr<BaseState> gameState(new GameState());
        return gameState;
    }
    case State::GAME_OVER:
    {
        std::shared_ptr<BaseState> gameOverState(new GameOverState());
        return gameOverState;
    }
    case State::WIN:
    {
        std::shared_ptr<BaseState> winState(new WinState());
        return winState;
    }
    }
}
