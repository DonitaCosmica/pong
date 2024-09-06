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

    Racquet(int, int, float);

  private:
    float speed;
  };
}

#endif // !RACQUET_HPP
