#include "Point.hpp"
#include <cmath>

namespace pong {
  Point::Point() : x(0), y(0) {}

  Point::Point(int x, int y) : x(x), y(y) {}

  Point::Point(const Point &other)
  {
    x = other.x;
    y = other.y;
  }

  Point& Point::operator=(const Point &other)
  {
    if(this == &other)
      return *this;

    x = other.x;
    y = other.y;
    return *this;
  }

  Point Point::operator+(const Point &other) const
  {
    return Point(x + other.x, y + other.y);
  }

  Point Point::operator-(const Point &other) const
  {
    return Point(x - other.x, y - other.y);
  }

  Point& Point::operator+=(const Point &other)
  {
    x += other.x;
    y += other.y;
    return *this;
  }

  Point& Point::operator-=(const Point &other)
  {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  int Point::distanceTo(const Point &other) const
  {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
  }
}
