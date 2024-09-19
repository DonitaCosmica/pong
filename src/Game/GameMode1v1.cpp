#include "GameMode1v1.hpp"

namespace pong {
  GameMode1v1::GameMode1v1(std::unique_ptr<Board> board, std::shared_ptr<Player> player1,
    std::shared_ptr<Player> player2, std::unique_ptr<Ball> ball)
  : GameMode(std::move(board), std::move(player1), std::move(player2), std::move(ball)) {}

  std::pair<std::string, std::string> GameMode1v1::getPlayerNames() const
  {
    return std::make_pair(player1->getName(), player2->getName());
  }
}
