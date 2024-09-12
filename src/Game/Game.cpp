#include "Game.hpp"

namespace pong {
  Game::Game(UIManager *uiManager, InputManager *inputManager, GameMode *gameMode)
    : uiManager(uiManager), inputManager(inputManager), gameMode(gameMode), state(GameState::PLAYING)
  {
    initializeGame();
  }

  void Game::initializeGame()
  {
    uiManager->clearScreen();
    auto [player1, player2] = gameMode->getPlayerNames();
    auto [scoreTeam1, scoreTeam2] = gameMode->getScores();

    if(uiManager && gameMode)
    {
      uiManager->drawScore(player1, player2, scoreTeam1, scoreTeam2);
      uiManager->drawBorder("game");

      auto player1Racquet = gameMode->getPlayer1().getRacquet();
      auto player1Side = gameMode->getPlayer1().getSide();

      auto player2Racquet = gameMode->getPlayer2().getRacquet();
      auto player2Side = gameMode->getPlayer2().getSide();

      if(player1Racquet && player2Racquet)
      {
        uiManager->drawRacquet(*player1Racquet, *player1Side);
        uiManager->drawRacquet(*player2Racquet, *player2Side);
        uiManager->drawBall(gameMode->getBall());
      }
    }
  }

  void Game::run()
  {
    while(state != GameState::GAME_OVER)
    {
      try
      {
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
