#ifndef GAMEMODE1V1_HPP
#define GAMEMODE1V1_HPP

#include "GameMode.hpp"
#include "../Entities/Board.hpp"
#include "../Entities/Player.hpp"
#include "../Entities/Ball.hpp"
#include "../Entities/Score.hpp"

namespace pong {
  class GameMode1v1 : public GameMode {
  public:
    GameMode1v1() = default;
    GameMode1v1(GameMode1v1 &&) = default;
    GameMode1v1(const GameMode1v1 &) = default;
    GameMode1v1 &operator=(GameMode1v1 &&) = default;
    GameMode1v1 &operator=(const GameMode1v1 &) = default;
    ~GameMode1v1();

    void initializeGame(TerminalManager *terminalManager) override;

  private:
    Board *board;
    Score *score;
    Player *player1;
    Player *player2;
    Ball *ball;
  };
}

#endif // !GAMEMODE1V1_HPP
