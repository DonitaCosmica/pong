#include "BallManager.hpp"
#include <cmath>

namespace pong {
  void BallManager::update(Ball &ball, const Board &board, const Racquet &racquet1, const Racquet &racquet2, Score &score)
  {
    ball.updatePosition();
    checkCollisions(ball, board, racquet1, racquet2, score);
  }

  void BallManager::checkCollisions(Ball &ball, const Board &board, const Racquet &racquet1, const Racquet &racquet2, Score &score)
  {
    if(ball.getPoint().y <= board.getTopLimit() || ball.getPoint().y >= board.getBottomLimit())
    {
      Vector normal(0, -1);
      if(ball.getPoint().y >= board.getBottomLimit())
        normal = Vector(0, 1);

      Vector reflectedDirection = ball.getDirection().reflect(normal);
      float newAngle = std::atan2(reflectedDirection.y, reflectedDirection.x) * 180.0f / M_PI;
      ball.setDirection(newAngle);
    }

    if(isCollidingWithRacquet(ball, racquet1))
    {
      float hitPos = (ball.getPoint().y - racquet1.getTop().y) / racquet1.getHeight();
      float newAngle = 45 * (2 * hitPos - 1);
      ball.setDirection(newAngle);
      ball.increaseSpeed();
    }

    if(isCollidingWithRacquet(ball, racquet2))
    {
      float hitPos = (ball.getPoint().y - racquet2.getTop().y) / racquet2.getHeight();
      float newAngle = 45 * (2 * hitPos - 1);
      ball.setDirection(180.0f - newAngle);
      ball.increaseSpeed();
    }

    if(ball.getPoint().x <= board.getLeftLimit())
    {
      score.update(Side::Position::LEFT);
      ball.resetPosition();
      ball.resetSpeed();
      ball.setDirection(0);
    }

    if(ball.getPoint().x >= board.getRightLimit())
    {
      score.update(Side::Position::RIGHT);
      ball.resetPosition();
      ball.resetSpeed();
      ball.setDirection(180);
    }
  }

  bool BallManager::isCollidingWithRacquet(const Ball &ball, const Racquet &racquet)
  {
    const Point ballPos = ball.getPoint();
    const Point racquetTop = racquet.getTop();
    const Point racquetBottom = racquet.getBottom();

    return (std::abs(ballPos.x - racquetTop.x) <= 1) && (ballPos.y >= racquetTop.y && ballPos.y <= racquetBottom.y);
  }
}
