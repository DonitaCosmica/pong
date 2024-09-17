#include "Board.hpp"

namespace pong {
  Board::Board(std::vector<Point> &points, int width, int height)
    : Entity(points, width, height)
  {
    topLimit = points[1].y;
    bottomLimit = points[2].y;
    leftLimit = points[3].x;
    rightLimit = points[4].x;
  }

  const Point& Board::getOrigin() const { return points[0]; }

  const Point& Board::getTop() const { return points[1]; }

  const Point& Board::getBottom() const { return points[2]; }

  const Point& Board::getLeft() const { return points[3]; }

  const Point& Board::getRight() const { return points[4]; }

  int Board::getTopLimit() const { return topLimit; }

  int Board::getBottomLimit() const { return bottomLimit; }

  int Board::getLeftLimit() const { return leftLimit; }

  int Board::getRightLimit() const { return rightLimit; }
}
