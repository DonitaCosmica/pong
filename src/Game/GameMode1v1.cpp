#include "GameMode1v1.hpp"

namespace pong {
  void GameMode1v1::initializeGame(TerminalManager *terminalManager)
  {
    TerminalManager::TerminalSize terminalSize = terminalManager->getTerminalSize();

    int boardWidth = terminalSize.cols - 2;
    int boardHeight = terminalSize.rows - 2;

    board = new Board(boardWidth, boardHeight);
    player1 = new Player();
    player2 = new Player();
    ball = new Ball();
  }

  GameMode1v1::~GameMode1v1()
  {
    delete board;
    delete player1;
    delete player2;
    delete ball;
  }
}
