#include "MovementManager.hpp"

namespace pong {
  void MovementManager::updatePosition(Ball &ball)
  {
    Vector pos = ball.getPosition();
    Vector dir = ball.getDirection();

    pos.x += dir.x * ball.getSpeed();
    pos.y += dir.y * ball.getSpeed();

    ball.setPosition(pos.x, pos.y);
  }

  void MovementManager::increaseSpeed(Ball &ball) { ball.increaseSpeed(); }
}
