#include "Ball.hpp"
#include <cmath>

namespace pong {
  Ball::Ball(float x, float y)
    : position(x, y), direction(1, 0), speed(1.0f), origin(x, y) {}

  Vector Ball::getPosition() const { return position; }

  void Ball::setPosition(float x, float y) { position = Vector(x, y); }

  Vector Ball::getDirection() const { return direction; }

  void Ball::setDirection(float angle)
  {
    float radians = angle * M_PI / 180.0f;
    direction.x = std::cos(radians);
    direction.y = std::sin(radians);
  }

  void Ball::resetPosition() { setPosition(origin.x, origin.y); }

  void Ball::resetSpeed() { speed = 1.0f; }

  void Ball::increaseSpeed() { speed += 0.1f; }

  float Ball::getSpeed() const { return speed; }
}
