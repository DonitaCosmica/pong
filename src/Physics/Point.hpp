#ifndef POINT_HPP
#define POINT_HPP

#include <string>

namespace pong {
  struct Point {
    Point();
    Point(Point &&) = default;
    Point(const Point &);
    Point &operator=(Point &&) = default;
    Point &operator=(const Point &);
    ~Point() = default;

    Point(int, int);
    Point operator+(const Point&) const;
    Point operator-(const Point&) const;
    Point &operator+=(const Point&);
    Point &operator-=(const Point&);

    int distanceTo(const Point&) const;
    std::string to_string() const;

    int x;
    int y;
  };
}

#endif // !POINT_HPP
