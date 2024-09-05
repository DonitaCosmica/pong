#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Physics/Point.hpp"

namespace pong {
  class Entity {
  public:
    Entity() = default;
    Entity(Entity &&) = default;
    Entity(const Entity &) = default;
    Entity &operator=(Entity &&) = default;
    Entity &operator=(const Entity &) = default;
    virtual ~Entity() = default;

    Entity(Point, int, int);

    Point& getPosition();
    int getWidth() const;
    int getHeight() const;

  protected:
    Point position;
    int width;
    int height;
  };
}

#endif // !ENTITY_HPP
