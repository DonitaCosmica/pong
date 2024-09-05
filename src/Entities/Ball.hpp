#ifndef BALL_HPP
#define BALL_HPP

#include "../Physics/Vector.hpp"

namespace pong {
  class Ball {
  public:
    Ball() = default;
    Ball(Ball &&) = default;
    Ball(const Ball &) = default;
    Ball &operator=(Ball &&) = default;
    Ball &operator=(const Ball &) = default;
    ~Ball() = default;

    Ball(Point, float, float);

    float getRadius() const;
    void setSpeed(float);
    void bounce(bool);

  private:
    Vector position;
    float speed;
    float radius;
  };
}

#endif // !BALL_HPP
