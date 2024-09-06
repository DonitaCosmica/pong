#ifndef GAMEMODE2V1_HPP
#define GAMEMODE2V1_HPP

#include "GameMode.hpp"
#include "../Entities/Board.hpp"
#include "../Entities/Player.hpp"
#include "../Entities/Ball.hpp"
#include "../Entities/Score.hpp"

namespace pong {
  class GameMode2v1 : public GameMode {
  public:
    GameMode2v1() = default;
    GameMode2v1(GameMode2v1 &&) = default;
    GameMode2v1(const GameMode2v1 &) = default;
    GameMode2v1 &operator=(GameMode2v1 &&) = default;
    GameMode2v1 &operator=(const GameMode2v1 &) = default;
    ~GameMode2v1() = default;

    void initializeGame(TerminalManager *terminalManager) override;

  private:
    Board *board;
    Score *score;
    Player *player1;
    Player *player2a;
    Player *player3a;
    Ball *ball;
  };
}

#endif // !GAMEMODE2V1_HPP
