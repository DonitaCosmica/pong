#ifndef SIDE_HPP
#define SIDE_HPP

#include "Racquet.hpp"

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

    Side(Position, Racquet*);

    bool isLeft() const;
    bool isRight() const;

  private:
    Position position;
    Racquet *racquet;
  };
}

#endif // !SIDE_HPP
