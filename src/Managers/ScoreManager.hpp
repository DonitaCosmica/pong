#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

#include "../Entities/Score.hpp"

namespace pong {
  class ScoreManager {
  public:
    ScoreManager() = default;
    ScoreManager(ScoreManager &&) = default;
    ScoreManager(const ScoreManager &) = default;
    ScoreManager &operator=(ScoreManager &&) = default;
    ScoreManager &operator=(const ScoreManager &) = default;
    ~ScoreManager() = default;

    static void update(Side::Position);
  };
}

#endif // !SCOREMANAGER_HPP
