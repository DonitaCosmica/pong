#ifndef GAMEMODEBUILDER_HPP
#define GAMEMODEBUILDER_HPP

#include "../Entities/Board.hpp"
#include "../Entities/Score.hpp"
#include "../Entities/Player.hpp"
#include "../Entities/Ball.hpp"
#include "GameMode1v1.hpp"
#include "GameMode2v1.hpp"

namespace pong {
  class GameModeBuilder {
  public:
    GameModeBuilder() = default;
    GameModeBuilder(GameModeBuilder &&) = default;
    GameModeBuilder(const GameModeBuilder &) = delete;
    GameModeBuilder &operator=(GameModeBuilder &&) = default;
    GameModeBuilder &operator=(const GameModeBuilder &) = delete;
    ~GameModeBuilder() = default;

    GameModeBuilder& setBoard(int, int);
    GameModeBuilder& setScore();
    GameModeBuilder& addPlayer1();
    GameModeBuilder& addPlayer2();
    GameModeBuilder& addPlayer3();
    GameModeBuilder& addBall();
    std::unique_ptr<GameMode1v1> build1v1();
    std::unique_ptr<GameMode2v1> build2v1();

  private:
    std::unique_ptr<Board> board;
    std::unique_ptr<Score> score;
    std::unique_ptr<Player> player1, player2, player3;
    std::unique_ptr<Ball> ball;
  };
}

#endif // !GAMEMODEBUILDER_HPP 
