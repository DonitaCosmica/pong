#include "Racquet.hpp"

namespace pong {
  Racquet::Racquet(int width, int height, float speed)
    : Entity({ Point(0, 0), Point(0, 0) }, width, height), speed(speed) {}
}
