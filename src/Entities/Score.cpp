#include "Score.hpp"

namespace pong {
  Score::Score() : team1Score(0), team2Score(0) {}

  Score& Score::getInstance()
  {
    static Score instance;
    return instance;
  }

  int Score::getTeam1Score() const { return team1Score; }

  int Score::getTeam2Score() const { return team2Score; }

  std::pair<int, int> Score::getScores() const
  {
    return std::make_pair(team1Score, team2Score);
  }

  void Score::incrementTeam1() { team1Score++; }

  void Score::incrementTeam2() { team2Score++; }

  void Score::reset()
  {
    team1Score = 0;
    team2Score = 0;
  }
}
