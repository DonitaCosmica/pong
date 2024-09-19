#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "../Entities/Board.hpp"
#include "../Entities/Ball.hpp"
#include "../Entities/Racquet.hpp"
#include "../Physics/Vector.hpp"

namespace pong {
  class CollisionManager {
  public:
    CollisionManager() = default;
    CollisionManager(CollisionManager &&) = default;
    CollisionManager(const CollisionManager &) = default;
    CollisionManager &operator=(CollisionManager &&) = default;
    CollisionManager &operator=(const CollisionManager &) = default;
    ~CollisionManager() = default;

    static void checkCollisions(Ball&, const Board&, const Racquet&, const Racquet&);
    static bool isCollidingWithRacquet(const Ball&, const Racquet&);
  };
}

#endif // !COLLISIONMANAGER_HPP
