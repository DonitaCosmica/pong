#include "GameMode1v1.hpp"

namespace pong {
  GameMode1v1::GameMode1v1(std::unique_ptr<Board> board, std::unique_ptr<Score> score,
    std::unique_ptr<Player> player1, std::unique_ptr<Player> player2, std::unique_ptr<Ball> ball) :
    board(std::move(board)), score(std::move(score)), player1(std::move(player1)),
    player2(std::move(player2)), ball(std::move(ball)) {}

  void GameMode1v1::initializeGame()
  {

  }
}
