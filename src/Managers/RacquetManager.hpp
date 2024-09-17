#ifndef RACQUETMANAGER_HPP
#define RACQUETMANAGER_HPP

#include "../Entities/Racquet.hpp"
#include "../Entities/Board.hpp"

namespace pong {
  class RacquetManager {
  public:
    RacquetManager() = default;
    RacquetManager(RacquetManager &&) = default;
    RacquetManager(const RacquetManager &) = default;
    RacquetManager &operator=(RacquetManager &&) = default;
    RacquetManager &operator=(const RacquetManager &) = default;
    ~RacquetManager() = default;

    static void moveUp(Racquet&, const Board&);
    static void moveDown(Racquet&, const Board&);

  private:
    static float speed;
  };
}

#endif // !RACQUETMANAGER_HPP
