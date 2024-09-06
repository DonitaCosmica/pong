#include "Player.hpp"

namespace pong {
  Player::Player(const std::string &name, Side *side, Racquet *racquet)
    : name(name), side(side), racquet(racquet) {}
}
