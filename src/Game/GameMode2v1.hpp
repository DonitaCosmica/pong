#ifndef GAMEMODE2V1_HPP
#define GAMEMODE2V1_HPP

#include "GameMode.hpp"

namespace pong {
  class GameMode2v1 : public GameMode {
  public:
    GameMode2v1() = default;
    GameMode2v1(GameMode2v1 &&) = default;
    GameMode2v1(const GameMode2v1 &) = default;
    GameMode2v1 &operator=(GameMode2v1 &&) = default;
    GameMode2v1 &operator=(const GameMode2v1 &) = default;
    ~GameMode2v1() = default;

    void initializeGame() override;

  private:

  };
}

#endif // !GAMEMODE2V1_HPP
