#ifndef RACQUET_HPP
#define RACQUET_HPP

#include "Entity.hpp"

namespace pong {
  class Racquet : public Entity {
  public:
    Racquet() = default;
    Racquet(Racquet &&) = default;
    Racquet(const Racquet &) = default;
    Racquet &operator=(Racquet &&) = default;
    Racquet &operator=(const Racquet &) = default;
    ~Racquet() = default;

    Racquet(std::vector<Point>&, int, int);

    const Point& getTop() const;
    const Point& getBottom() const;

    void setPosition(const Point&, const Point&);
  };
}

#endif // !RACQUET_HPP
