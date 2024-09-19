#include "Ball.hpp"
#include <cmath>

namespace pong {
  Ball::Ball(float x, float y)
    : position(x, y), direction(1, 0), speed(1.0f), origin(x, y) {}

  void Ball::updatePosition()
  {
    position.x += direction.x * speed;
    position.y += direction.y * speed;
  }

  void Ball::setDirection(float angle)
  {
    float radians = angle * M_PI / 180.0f;
    direction.x = std::cos(radians);
    direction.y = std::sin(radians);
  }

  float Ball::getAngle() const
  {
    return std::atan2(direction.y, direction.x) * 180.0f / M_PI;
  }

  const Point Ball::getPoint() const
  {
    return Point(position.x, position.y);
  }

  Vector Ball::getDirection() const { return direction; }

  void Ball::setPosition(int x, int y)
  {
    position = Vector(x, y);
  }

  void Ball::resetPosition()
  {
    setPosition(origin.x, origin.y);
  }

  void Ball::increaseSpeed() { speed += 0.1f; }

  void Ball::resetSpeed() { speed = 1.0f; }
}
