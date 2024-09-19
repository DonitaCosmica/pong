#include "BallManager.hpp"
#include "../Managers/CollisionManager.hpp"
#include "../Managers/MovementManager.hpp"

namespace pong {
  void BallManager::update(Ball &ball, const Board &board, const Racquet &racquet1, const Racquet &racquet2)
  {
    MovementManager::updatePosition(ball);
    CollisionManager::checkCollisions(ball, board, racquet1, racquet2);
  }
}
