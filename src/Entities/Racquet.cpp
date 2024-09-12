#include "Racquet.hpp"

namespace pong {
  Racquet::Racquet(std::vector<Point> &points, int width, int height)
    : Entity(points, width, height) {}

  const Point& Racquet::getTop() const { return points[0]; }

  const Point& Racquet::getBottom() const { return points[1]; }
}
