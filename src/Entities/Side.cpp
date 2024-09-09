#include "Side.hpp"
#include "Player.hpp"

namespace pong {
  Side::Side(Position position, std::shared_ptr<Player> player) :
    position(position), player(player) {}

  bool Side::isLeft() const { return position == Position::LEFT; }

  bool Side::isRight() const { return position == Position::RIGHT; }

  std::shared_ptr<Racquet> Side::getRacquet() const
  {
    return player->getRacquet();
  }
}
