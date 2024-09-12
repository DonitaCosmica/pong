#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <memory>
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

    Player(const std::string&, std::shared_ptr<Side>, std::shared_ptr<Racquet>);

    std::string getName() const;
    std::shared_ptr<Side> getSide() const;
    std::shared_ptr<Racquet> getRacquet() const;

  private:
    std::string name;
    std::shared_ptr<Side> side;
    std::shared_ptr<Racquet> racquet;
  };
}

#endif // !PLAYER_HPP
