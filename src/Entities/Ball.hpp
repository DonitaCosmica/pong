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

    Ball(int, int, int, int);

    float getRadius() const;
    void setSpeed(int);
    void bounce(bool);

  private:
    Vector position;
    int speed;
    int radius;
  };
}

#endif // !BALL_HPP
