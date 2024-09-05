#include "Vector.hpp"
#include <cmath>

namespace pong {
  Vector::Vector() : Point() {}

  Vector::Vector(float x, float y) : Point(x, y) {}

  Vector& Vector::operator=(const Vector &other)
  {
    if(this == &other)
      return *this;

    x = other.x;
    y = other.y;
    return *this;
  }

  Vector Vector::operator+(const Vector &other) const
  {
    return Vector(x + other.x, y + other.y);
  }

  Vector Vector::operator-(const Vector &other) const
  {
    return Vector(x - other.x, y - other.y);
  }

  Vector& Vector::operator+=(const Vector &other)
  {
    x += other.x;
    y += other.y;
    return *this;
  }

  Vector& Vector::operator-=(const Vector &other)
  {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  Vector Vector::scale(float scalar) const
  {
    return Vector(x * scalar, y * scalar);
  }

  Vector Vector::reflect(const Vector &normal) const
  {
    float dotProduct = x * normal.x + y * normal.y;
    return Vector(x - 2 * dotProduct * normal.x, y - 2 * dotProduct * normal.y);
  }

  Vector& Vector::normalize()
  {
    float magnitude = getMagnitude();
    if(magnitude != 0)
    {
      x /= magnitude;
      y /= magnitude;
    }

    return *this;
  }

  float Vector::getMagnitude() const
  {
    return std::sqrt(x * x + y * y);
  }

  float Vector::angleBetween(const Vector &other) const
  {
    float dotProduct = x * other.x + y * other.y;
    float magnitudeA = std::sqrt(x * x + y * y);
    float magnitudeB = std::sqrt(other.x * other.x + other.y * other.y);
    return std::acos(dotProduct / (magnitudeA * magnitudeB));
  }
}
