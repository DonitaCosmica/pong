#include "Ball.hpp"

namespace pong {
  Ball::Ball(int x, int y, int speed, int radius) : speed(speed), radius(radius)
  {
    position = Vector(x, y);
  }
}
