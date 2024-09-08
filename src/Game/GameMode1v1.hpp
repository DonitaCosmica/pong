#ifndef GAMEMODE1V1_HPP
#define GAMEMODE1V1_HPP

#include "GameMode.hpp"
#include "../Entities/Board.hpp"
#include "../Entities/Player.hpp"
#include "../Entities/Ball.hpp"
#include "../Entities/Score.hpp"

namespace pong {
  class GameMode1v1 : public GameMode {
  public:
    GameMode1v1() = default;
    GameMode1v1(GameMode1v1 &&) = default;
    GameMode1v1(const GameMode1v1 &) = default;
    GameMode1v1 &operator=(GameMode1v1 &&) = default;
    GameMode1v1 &operator=(const GameMode1v1 &) = default;
    ~GameMode1v1() = default;

    GameMode1v1(std::unique_ptr<Board>, std::unique_ptr<Score>,
      std::unique_ptr<Player>, std::unique_ptr<Player>, std::unique_ptr<Ball>);

    void initializeGame() override;

  private:
    std::unique_ptr<Board> board;
    std::unique_ptr<Score> score;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    std::unique_ptr<Ball> ball;
  };
}

#endif // !GAMEMODE1V1_HPP
