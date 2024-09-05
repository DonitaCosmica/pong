#include "Entity.hpp"

namespace pong {
  Entity::Entity(Point position, float width, float height) :
    position(position), width(width), height(height) {}

  Point& Entity::getPosition() { return position; }

  float Entity::getWidth() const { return width; }

  float Entity::getHeight() const { return height; }
}
