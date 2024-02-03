#include "game_state_factory.h"
#include "game_over_state.h"
#include "win_state.h"
#include "menu_state.h"
#include "settings_state.h"
#include "game_state.h"
#include "score_state.h"

std::shared_ptr<BaseState> GameStateFactory::CreateGameState(State state)
{
    switch (state)
    {
    case State::MENU:
    {
        std::shared_ptr<BaseState> menu_state(new MenuState());
        return menu_state;
    }
    case State::SETTINGS:
    {
        std::shared_ptr<BaseState> settings_state(new SettingsState());
        return settings_state;
    }
    case State::GAME:
    {
        std::shared_ptr<BaseState> game_state(new GameState());
        return game_state;
    }
    case State::GAME_OVER:
    {
        std::shared_ptr<BaseState> game_over_state(new GameOverState());
        return game_over_state;
    }
    case State::WIN:
    {
        std::shared_ptr<BaseState> win_state(new WinState());
        return win_state;
    }
    case State::SCORE:
    {
        std::shared_ptr<BaseState> score_state(new ScoreState());
        return score_state;
    }
    default:
    {
        std::shared_ptr<BaseState> menu_state(new MenuState());
        return menu_state;
    }
    }
}
