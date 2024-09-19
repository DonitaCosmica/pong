#ifndef SCORE_HPP
#define SCORE_HPP

#include <utility>
#include "Side.hpp"

namespace pong {
  class Score {
  public:
    Score();
    Score(Score &&) = default;
    Score(const Score &) = default;
    Score &operator=(Score &&) = default;
    Score &operator=(const Score &) = default;
    ~Score() = default;

    int getTeam1Score() const;
    int getTeam2Score() const;
    void update(Side::Position);
    std::pair<int, int> getScores() const;

  private:
    int team1Score;
    int team2Score;
  };
}

#endif // !SCORE_HPP
