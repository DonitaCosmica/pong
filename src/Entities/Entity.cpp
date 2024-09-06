#include "Entity.hpp"

namespace pong {
  Entity::Entity(const std::vector<Point> &points, int width, int height) :
    points(points), width(width), height(height) {}

  int Entity::getWidth() const { return width; }

  int Entity::getHeight() const { return height; }
}
