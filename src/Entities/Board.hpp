#ifndef BOARD_HPP
#define BOARD_HPP

#include "Entity.hpp"

namespace pong {
  class Board : public Entity {
  public:
    Board() = delete;
    Board(Board &&) = default;
    Board(const Board &) = delete;
    Board &operator=(Board &&) = default;
    Board &operator=(const Board &) = delete;
    ~Board() = default;

    Board(std::vector<Point>&, int, int);

    const Point& getOrigin() const;
    const Point& getTop() const;
    const Point& getBottom() const;
    const Point& getLeft() const;
    const Point& getRight() const;

    int getTopLimit() const;
    int getBottomLimit() const;
    int getLeftLimit() const;
    int getRightLimit() const;

  private:
    int topLimit;
    int bottomLimit;
    int leftLimit;
    int rightLimit;
  };
}

#endif // !BOARD_HPP
