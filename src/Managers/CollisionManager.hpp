#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "../Entities/Board.hpp"
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

    bool checkCollision() const;

  private:
    
  };
}

#endif // !COLLISIONMANAGER_HPP
