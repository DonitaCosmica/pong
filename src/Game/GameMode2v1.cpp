#include "GameMode2v1.hpp"

namespace pong {
  GameMode2v1::GameMode2v1(std::unique_ptr<Board> board, std::unique_ptr<Score> score,
    std::shared_ptr<Player> player1, std::shared_ptr<Player> player2,
    std::shared_ptr<Player> player3, std::unique_ptr<Ball> ball)
  : GameMode(std::move(board), std::move(score), std::move(player1), std::move(player2), std::move(ball)),
    player3(std::move(player3)) {}

  std::pair<std::string, std::string> GameMode2v1::getPlayerNames() const
  {
    std::string team = player2->getName().substr(0, 3) + player3->getName().substr(2, 2);
    return std::make_pair(player1->getName(), team);
  }
}
