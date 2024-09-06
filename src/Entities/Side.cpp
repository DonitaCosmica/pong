#include "Side.hpp"

namespace pong {
  Side::Side(Position position, Racquet *racquet) : position(position), racquet(racquet) {}

  bool Side::isLeft() const { return position == Position::LEFT; }

  bool Side::isRight() const { return position == Position::RIGHT; }
}
