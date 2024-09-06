#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Side.hpp"
#include "Racquet.hpp"

namespace pong {
  class Player {
  public:
    Player() = default;
    Player(Player &&) = default;
    Player(const Player &) = default;
    Player &operator=(Player &&) = default;
    Player &operator=(const Player &) = default;
    ~Player() = default;

    Player(const std::string&, Side*, Racquet*);

  private:
    std::string name;
    Side *side;
    Racquet *racquet;
  };
}

#endif // !PLAYER_HPP
