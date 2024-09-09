#include "Player.hpp"

namespace pong {
  Player::Player(const std::string &name, std::shared_ptr<Side> side, std::shared_ptr<Racquet> racquet)
    : name(name), side(side), racquet(racquet) {}

  std::string Player::getName() const { return name; }

  std::shared_ptr<Racquet> Player::getRacquet() const { return racquet; }
}
