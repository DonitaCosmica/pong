#ifndef SCORE_HPP
#define SCORE_HPP

#include <utility>
#include "Side.hpp"

namespace pong {
  class Score {
  public:
    Score(Score &&) = default;
    Score(const Score &) = delete;
    Score &operator=(Score &&) = default;
    Score &operator=(const Score &) = delete;

    static Score& getInstance();
    int getTeam1Score() const;
    int getTeam2Score() const;
    std::pair<int, int> getScores() const;
    void incrementTeam1();
    void incrementTeam2();
    void reset();

  private:
    Score();
    ~Score() = default;

    int team1Score;
    int team2Score;
  };
}

#endif // !SCORE_HPP
