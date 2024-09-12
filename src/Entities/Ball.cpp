#include "Ball.hpp"

namespace pong {
  Ball::Ball(int x, int y)
  {
    position = Vector(x, y);
  }

  const Point Ball::getPoint() const
  {
    return Point(position.x, position.y);
  }
}
