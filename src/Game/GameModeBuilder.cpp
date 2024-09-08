#include "GameModeBuilder.hpp"

namespace pong {
  GameModeBuilder& GameModeBuilder::setBoard(int width, int height)
  {
    board = std::make_unique<Board>(width, height);
    return *this;
  }

  GameModeBuilder& GameModeBuilder::setScore()
  {
    score = std::make_unique<Score>();
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addPlayer1()
  {
    player1 = std::make_unique<Player>();
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addPlayer2()
  {
    player2 = std::make_unique<Player>();
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addPlayer3()
  {
    player3 = std::make_unique<Player>();
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addBall()
  {
    ball = std::make_unique<Ball>();
    return *this;
  }

  std::unique_ptr<GameMode1v1> GameModeBuilder::build1v1()
  {
    return std::make_unique<GameMode1v1>(
      std::move(board), std::move(score), std::move(player1),
      std::move(player2), std::move(ball));
  }

  std::unique_ptr<GameMode2v1> GameModeBuilder::build2v1()
  {
    return std::make_unique<GameMode2v1>(
      std::move(board), std::move(score), std::move(player1),
      std::move(player2), std::move(player3),
      std::move(ball));
  }
}
