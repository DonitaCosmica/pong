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

    Vector(int, int);
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Vector &operator+=(const Vector&);
    Vector &operator-=(const Vector&);

    Vector reflect(const Vector&) const;
    Vector scale(int) const;
    Vector &normalize();

    int getMagnitude() const;
    int angleBetween(const Vector&) const;
  };
}

#endif // !VECTOR_HPP
