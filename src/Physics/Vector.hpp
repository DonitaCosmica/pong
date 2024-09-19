#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Point.hpp"

namespace pong {
  struct Vector : public Point {
    Vector();
    Vector(Vector &&) = default;
    Vector(const Vector &);
    Vector &operator=(Vector &&) = default;
    Vector &operator=(const Vector &);
    ~Vector() = default;

    Vector(float, float);
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Vector &operator+=(const Vector&);
    Vector &operator-=(const Vector&);

    Vector reflect(const Vector&) const;
    Vector scale(float) const;
    Vector &normalize();

    float getMagnitude() const;
    float angleBetween(const Vector&) const;
  };
}

#endif // !VECTOR_HPP
