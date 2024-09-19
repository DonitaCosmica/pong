#include "Point.hpp"
#include <cmath>
#include <sstream>

namespace pong {
  Point::Point() : x(0), y(0) {}

  Point::Point(float x, float y) : x(x), y(y) {}

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

  float Point::distanceTo(const Point &other) const
  {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
  }

  std::string Point::to_string() const
  {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ")";
    return oss.str();
  }
}
