#include "Racquet.hpp"

namespace pong {
  Racquet::Racquet(std::vector<Point> &points, int width, int height)
    : Entity(points, width, height) {}

  const Point& Racquet::getTop() const { return points[0]; }

  const Point& Racquet::getBottom() const { return points[1]; }

  void Racquet::setPosition(const Point &top, const Point &bottom)
  {
    points[0] = top;
    points[1] = bottom;
  }
}
