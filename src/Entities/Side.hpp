#ifndef SIDE_HPP
#define SIDE_HPP

#include <memory>
#include "Racquet.hpp"

namespace pong {
  class Player;
}

namespace pong {
  class Side {
  public:
    Side() = default;
    Side(Side &&) = default;
    Side(const Side &) = default;
    Side &operator=(Side &&) = default;
    Side &operator=(const Side &) = default;
    ~Side() = default;

    enum class Position {
      LEFT,
      RIGHT
    };

    Side(Position, std::shared_ptr<Player>);

    bool isLeft() const;
    bool isRight() const;
    std::shared_ptr<Racquet> getRacquet() const;

  private:
    Position position;
    std::shared_ptr<Player> player;
  };
}

#endif // !SIDE_HPP
