#ifndef BALL_HPP
#define BALL_HPP

#include "../Physics/Vector.hpp"
#include "Board.hpp"

namespace pong {
  class Ball {
  public:
    Ball() = default;
    Ball(Ball &&) = default;
    Ball(const Ball &) = default;
    Ball &operator=(Ball &&) = default;
    Ball &operator=(const Ball &) = default;
    ~Ball() = default;

    Ball(float, float);

    void updatePosition();
    void setDirection(float);
    float getAngle() const;
    const Point getPoint() const;
    Vector getDirection() const;
    void setPosition(int, int);
    void resetPosition();
    void increaseSpeed();
    void resetSpeed();

  private:
    Vector position;
    Vector direction;
    Point origin;
    float speed;
  };
}

#endif // !BALL_HPP
