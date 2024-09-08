#ifndef GAMEMODE2V1_HPP
#define GAMEMODE2V1_HPP

#include "GameMode.hpp"
#include "../Entities/Board.hpp"
#include "../Entities/Player.hpp"
#include "../Entities/Ball.hpp"
#include "../Entities/Score.hpp"

namespace pong {
  class GameMode2v1 : public GameMode {
  public:
    GameMode2v1() = default;
    GameMode2v1(GameMode2v1 &&) = default;
    GameMode2v1(const GameMode2v1 &) = default;
    GameMode2v1 &operator=(GameMode2v1 &&) = default;
    GameMode2v1 &operator=(const GameMode2v1 &) = default;
    ~GameMode2v1() = default;

    GameMode2v1(std::unique_ptr<Board>, std::unique_ptr<Score>,
      std::unique_ptr<Player>, std::unique_ptr<Player>, std::unique_ptr<Player>,
      std::unique_ptr<Ball>);

    void initializeGame() override;

  private:
    std::unique_ptr<Board> board;
    std::unique_ptr<Score> score;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2a;
    std::unique_ptr<Player> player3a;
    std::unique_ptr<Ball> ball;
  };
}

#endif // !GAMEMODE2V1_HPP
