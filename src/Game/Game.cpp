#include "Game.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <chrono>
#include <limits>
#include "../Managers/RacquetManager.hpp"
#include "../Managers/BallManager.hpp"
#include "../Entities/Score.hpp"

namespace pong {
  Game::Game(UIManager *uiManager, InputManager *inputManager, GameMode *gameMode)
    : uiManager(uiManager), inputManager(inputManager), gameMode(gameMode), state(GameState::PLAYING) {}

  void Game::run()
  {
    state = GameState::PLAYING;
    inputManager->start();
    uiManager->clearScreen();

    const int frameDelay = 1000 / 60;
    const int winnerScore = 5;

    auto [player1, player2] = gameMode->getPlayerNames();
    auto player1Racquet = gameMode->getPlayer1().getRacquet();
    auto player1Side = gameMode->getPlayer1().getSide();
    auto player2Racquet = gameMode->getPlayer2().getRacquet();
    auto player2Side = gameMode->getPlayer2().getSide(); 
    auto ball = gameMode->getBall();
    auto& score = Score::getInstance();

    uiManager->drawScore(player1, player2);

    while(state != GameState::GAME_OVER)
    {
      auto startFrame = std::chrono::steady_clock::now();
      auto [scoreTeam1, scoreTeam2] = score.getScores();

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

        BallManager::update(ball, gameMode->getBoard(), *player1Racquet, *player2Racquet);
        uiManager->render(state);

        if(scoreTeam1 == winnerScore)
        {
          uiManager->drawWinner(player1);
          state = GameState::GAME_OVER;
        }
        else if(scoreTeam2 == winnerScore)
        {
          uiManager->drawWinner(player2);
          state = GameState::GAME_OVER;
        }

        uiManager->drawRacquet(*player1Racquet, *player1Side);
        uiManager->drawRacquet(*player2Racquet, *player2Side);
        uiManager->drawBall(ball);
        refresh();

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

    endwin();
    uiManager->clearScreen();
    uiManager->drawBorder("init");
    score.reset();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}
