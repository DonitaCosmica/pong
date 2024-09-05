#ifndef SCORE_HPP
#define SCORE_HPP

namespace pong {
  class Score {
  public:
    Score();
    Score(Score &&) = default;
    Score(const Score &) = default;
    Score &operator=(Score &&) = default;
    Score &operator=(const Score &) = default;
    ~Score() = default;

    void updateScore(Player&);

  private:
    int team1Score;
    int team2Score;
  };
}

#endif // !SCORE_HPP
