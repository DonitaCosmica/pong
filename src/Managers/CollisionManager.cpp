#include "CollisionManager.hpp"
#include "MovementManager.hpp"
#include "ScoreManager.hpp"
#include <cmath>

namespace pong {
  void CollisionManager::checkCollisions(Ball &ball, const Board &board, const Racquet &racquet1, const Racquet &racquet2)
  {
    if(ball.getPosition().y <= board.getTopLimit() || ball.getPosition().y >= board.getBottomLimit())
    {
      Vector normal(0, -1);
      if(ball.getPosition().y >= board.getBottomLimit())
        normal = Vector(0, 1);

      Vector reflectedDirection = ball.getDirection().reflect(normal);
      float newAngle = std::atan2(reflectedDirection.y, reflectedDirection.x) * 180.0f / M_PI;
      ball.setDirection(newAngle);
    }

    if(isCollidingWithRacquet(ball, racquet1))
    {
      float hitPos = (ball.getPosition().y - racquet1.getTop().y) / racquet1.getHeight();
      float newAngle = 45 * (2 * hitPos - 1);
      ball.setDirection(newAngle);
      MovementManager::increaseSpeed(ball);
    }

    if(isCollidingWithRacquet(ball, racquet2))
    {
      float hitPos = (ball.getPosition().y - racquet2.getTop().y) / racquet2.getHeight();
      float newAngle = 45 * (2 * hitPos - 1);
      ball.setDirection(180.0f - newAngle);
      MovementManager::increaseSpeed(ball);
    }

    if(ball.getPosition().x <= board.getLeftLimit())
    {
      ScoreManager::update(Side::Position::LEFT);
      ball.resetPosition();
      ball.resetSpeed();
      ball.setDirection(0);
    }

    if(ball.getPosition().x >= board.getRightLimit())
    {
      ScoreManager::update(Side::Position::RIGHT);
      ball.resetPosition();
      ball.resetSpeed();
      ball.setDirection(180);
    }
  }

  bool CollisionManager::isCollidingWithRacquet(const Ball &ball, const Racquet &racquet)
  {
    const Point ballPos = ball.getPosition();
    const Point racquetTop = racquet.getTop();
    const Point racquetBottom = racquet.getBottom();

    return (std::abs(ballPos.x - racquetTop.x) <= 1) && (ballPos.y >= racquetTop.y && ballPos.y <= racquetBottom.y);
  }
}
