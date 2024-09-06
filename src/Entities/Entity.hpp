#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <vector>
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

    Entity(const std::vector<Point>&, int, int);

    const Point& getPoint(size_t index) const;
    int getWidth() const;
    int getHeight() const;

  protected:
    std::vector<Point> points;
    int width;
    int height;
  };
}

#endif // !ENTITY_HPP
