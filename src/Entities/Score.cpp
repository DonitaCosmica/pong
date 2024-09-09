#include "Score.hpp"

namespace pong {
  Score::Score() : team1Score(0), team2Score(0) {}

  int Score::getTeam1Score() const { return team1Score; }

  int Score::getTeam2Score() const { return team2Score; }
}
