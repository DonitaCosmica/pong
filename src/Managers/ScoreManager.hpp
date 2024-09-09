#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

namespace pong {
  class ScoreManager {
  public:
    ScoreManager() = default;
    ScoreManager(ScoreManager &&) = default;
    ScoreManager(const ScoreManager &) = default;
    ScoreManager &operator=(ScoreManager &&) = default;
    ScoreManager &operator=(const ScoreManager &) = default;
    ~ScoreManager() = default;

  private:
    
  };
}

#endif // !SCOREMANAGER_HPP
