#ifndef BALLMANAGER_HPP
#define BALLMANAGER_HPP

#include "../Entities/Ball.hpp"
#include "../Entities/Racquet.hpp"
#include "../Entities/Board.hpp"

namespace pong {
  class BallManager {
  public:
    BallManager() = default;
    BallManager(BallManager &&) = default;
    BallManager(const BallManager &) = default;
    BallManager &operator=(BallManager &&) = default;
    BallManager &operator=(const BallManager &) = default;
    ~BallManager() = default;

    static void update(Ball&, const Board&, const Racquet&, const Racquet&);
  };
}

#endif // !BALLMANAGER_HPP
