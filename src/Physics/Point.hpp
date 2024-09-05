#ifndef POINT_HPP
#define POINT_HPP

namespace pong {
  struct Point {
    Point();
    Point(Point &&) = default;
    Point(const Point &);
    Point &operator=(Point &&) = default;
    Point &operator=(const Point &);
    ~Point() = default;

    Point(float, float);
    Point operator+(const Point&) const;
    Point operator-(const Point&) const;
    Point &operator+=(const Point&);
    Point &operator-=(const Point&);

    float distanceTo(const Point&) const;

    float x;
    float y;
  };
}

#endif // !POINT_HPP
