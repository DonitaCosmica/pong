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

    Vector getPosition() const;
    void setPosition(float, float);
    Vector getDirection() const;
    void setDirection(float);
    void resetPosition();
    void resetSpeed();
    float getSpeed() const;
    void increaseSpeed();

  private:
    Vector position;
    Vector direction;
    Point origin;
    float speed;
  };
}

#endif // !BALL_HPP
