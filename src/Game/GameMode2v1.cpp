#include "GameMode2v1.hpp"

namespace pong {
  GameMode2v1::GameMode2v1(std::unique_ptr<Board> board, std::unique_ptr<Score> score,
    std::unique_ptr<Player> player1, std::unique_ptr<Player> player2a,
    std::unique_ptr<Player> player3a, std::unique_ptr<Ball> ball)
  : board(std::move(board)), score(std::move(score)),
    player1(std::move(player1)), player2a(std::move(player2a)),
    player3a(std::move(player3a)), ball(std::move(ball)) {}

  void GameMode2v1::initializeGame()
  {

  }
}
