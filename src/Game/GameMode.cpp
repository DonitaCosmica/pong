#include "GameMode.hpp"

namespace pong {
  GameMode::GameMode(std::unique_ptr<Board> board, std::unique_ptr<Score> score,
    std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, std::unique_ptr<Ball> ball)
  : board(std::move(board)), score(std::move(score)), player1(std::move(player1)),
    player2(std::move(player2)), ball(std::move(ball)) {}

  GameMode::Mode GameMode::getMode() const { return mode; }

  std::pair<int, int> GameMode::getScores() const
  {
    return std::make_pair(score->getTeam1Score(), score->getTeam2Score());
  }
}
