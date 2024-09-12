#ifndef BOARD_HPP
#define BOARD_HPP

#include "Entity.hpp"

namespace pong {
  class Board : public Entity {
  public:
    Board() = default;
    Board(Board &&) = default;
    Board(const Board &) = default;
    Board &operator=(Board &&) = default;
    Board &operator=(const Board &) = default;
    ~Board() = default;

    Board(std::vector<Point>&, int, int);

    const Point& getOrigin() const;
    const Point& getTop() const;
    const Point& getBottom() const;
    const Point& getLeft() const;
    const Point& getRight() const; 

  private:
  };
}

#endif // !BOARD_HPP
