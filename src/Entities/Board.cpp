#include "Board.hpp"

namespace pong {
  Board::Board(int width, int height) : Entity({
      Point(width / 2, 0), Point(width / 2, height),
      Point(0, height / 2), Point(width, height / 2)
    }, width, height) {}

  const Point& Board::getTop() const { return points[0]; }

  const Point& Board::getBottom() const { return points[1]; }

  const Point& Board::getLeft() const { return points[2]; }

  const Point& Board::getRight() const { return points[3]; }
}
