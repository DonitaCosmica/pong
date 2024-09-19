#include "ScoreManager.hpp"

namespace pong {
  void ScoreManager::update(Side::Position position)
  {
    auto& score = Score::getInstance();

    (position == Side::Position::LEFT)
      ? score.incrementTeam2()
      : score.incrementTeam1();
  }
}
