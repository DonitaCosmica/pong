#include "Game.hpp"

namespace pong {
  Game::Game(UIManager *uiManager, InputManager *inputManager, GameMode *gameMode)
    : uiManager(uiManager), inputManager(inputManager), gameMode(gameMode)
  {
    state = GameState::PLAYING;
  }

  void Game::run()
  {
    while(state != GameState::GAME_OVER)
    {
      try
      {
        system("clear");
        uiManager->drawScore();
        uiManager->drawBorder("game");
        getchar();
      }
      catch (const std::exception &e)
      {
        uiManager->showMessage(e.what(), pong::UIManager::MsgType::ERROR);
        uiManager->render(state);
      }
    }
  }
}
