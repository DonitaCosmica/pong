#include "Board.hpp"

namespace pong {
  Board::Board(int width, int height) : Entity(Point(0, 0), width, height) 
  {
    setBoundaryPoints();
  }

  const Point& Board::getTop() const { return top; }

  const Point& Board::getBottom() const { return bottom; }

  const Point& Board::getLeft() const { return left; }

  const Point& Board::getRight() const { return right; }

  void Board::setBoundaryPoints()
  {
    top = new Point(position.x + width / 2, position.y);
    bottom = new Point(position.x + width / 2, position.y + height);
    left = new Point(position.x, position.y + height / 2);
    right = new Point(position.x + width, position.y + height / 2);
  }

  Board::~Board()
  {
    delete top;
    delete bottom;
    delete left;
    delete right;
  }
}
