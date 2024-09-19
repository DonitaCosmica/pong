#ifndef MOVEMENTMANAGER_HPP
#define MOVEMENTMANAGER_HPP

#include "../Entities/Ball.hpp"

namespace pong {
  class MovementManager {
  public:
    MovementManager() = default;
    MovementManager(MovementManager &&) = default;
    MovementManager(const MovementManager &) = default;
    MovementManager &operator=(MovementManager &&) = default;
    MovementManager &operator=(const MovementManager &) = default;
    ~MovementManager() = default;

    static void updatePosition(Ball&);
    static void increaseSpeed(Ball&);
  };
}

#endif // !MOVEMENTMANAGER_HPP
