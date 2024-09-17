#include "Game.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <chrono>
#include "../Managers/RacquetManager.hpp"

namespace pong {
  Game::Game(UIManager *uiManager, InputManager *inputManager, GameMode *gameMode)
    : uiManager(uiManager), inputManager(inputManager), gameMode(gameMode), state(GameState::PLAYING) {}

  void Game::run()
  {
    inputManager->start();
    uiManager->clearScreen();

    const int frameDelay = 1000 / 60;

    auto [player1, player2] = gameMode->getPlayerNames();
    auto [scoreTeam1, scoreTeam2] = gameMode->getScores();
    auto player1Racquet = gameMode->getPlayer1().getRacquet();
    auto player1Side = gameMode->getPlayer1().getSide();
    auto player2Racquet = gameMode->getPlayer2().getRacquet();
    auto player2Side = gameMode->getPlayer2().getSide(); 
 
    uiManager->drawScore(player1, player2);

    while(state != GameState::GAME_OVER)
    {
      auto startFrame = std::chrono::steady_clock::now();

      try
      {
        inputManager->update();

        uiManager->drawBorder("game");
        uiManager->drawPoints(*player1Side, scoreTeam1, player1);
        uiManager->drawPoints(*player2Side, scoreTeam2, player2);

        if(inputManager->isKeyPressed('w'))
          RacquetManager::moveUp(*player1Racquet, gameMode->getBoard());

        if(inputManager->isKeyPressed('s'))
          RacquetManager::moveDown(*player1Racquet, gameMode->getBoard());

        if(inputManager->isKeyPressed(KEY_UP))
          RacquetManager::moveUp(*player2Racquet, gameMode->getBoard());

        if(inputManager->isKeyPressed(KEY_DOWN))
          RacquetManager::moveDown(*player2Racquet, gameMode->getBoard());

        uiManager->render(state);
        uiManager->drawRacquet(*player1Racquet, *player1Side);
        uiManager->drawRacquet(*player2Racquet, *player2Side);
        uiManager->drawBall(gameMode->getBall());
        refresh();

        if (inputManager->isKeyPressed('q'))
          state = GameState::GAME_OVER;

        auto endFrame = std::chrono::steady_clock::now();
        auto frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(endFrame - startFrame).count();
        if(frameTime < frameDelay)
          usleep((frameDelay - frameTime) * 1000);
      }
      catch (const std::exception &e)
      {
        uiManager->showMessage(e.what(), pong::UIManager::MsgType::ERROR);
        uiManager->render(state);
      }
    }
  }
}
