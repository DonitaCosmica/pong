#include "GameMode.hpp"

namespace pong {
  GameMode::GameMode(std::unique_ptr<Board> board, std::shared_ptr<Player> player1,
    std::shared_ptr<Player> player2, std::unique_ptr<Ball> ball)
  : board(std::move(board)), player1(std::move(player1)), player2(std::move(player2)),
    ball(std::move(ball)) {}

  GameMode::Mode GameMode::getMode() const { return mode; }

  const Board& GameMode::getBoard() const { return *board; }

  const Player& GameMode::getPlayer1() const { return *player1; }

  const Player& GameMode::getPlayer2() const { return *player2; }

  const Ball& GameMode::getBall() const { return *ball; }
}
