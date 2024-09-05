#ifndef BALLMANAGER_HPP
#define BALLMANAGER_HPP

namespace pong {
  class BallManager {
  public:
    BallManager() = default;
    BallManager(BallManager &&) = default;
    BallManager(const BallManager &) = default;
    BallManager &operator=(BallManager &&) = default;
    BallManager &operator=(const BallManager &) = default;
    ~BallManager() = default;

  private:
    
  };
}

#endif // !BALLMANAGER_HPP
