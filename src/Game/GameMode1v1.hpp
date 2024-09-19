#ifndef GAMEMODE1V1_HPP
#define GAMEMODE1V1_HPP

#include "GameMode.hpp"

namespace pong {
  class GameMode1v1 : public GameMode {
  public:
    GameMode1v1() = default;
    GameMode1v1(GameMode1v1 &&) = default;
    GameMode1v1(const GameMode1v1 &) = default;
    GameMode1v1 &operator=(GameMode1v1 &&) = default;
    GameMode1v1 &operator=(const GameMode1v1 &) = default;
    ~GameMode1v1() = default;

    GameMode1v1(std::unique_ptr<Board>, std::shared_ptr<Player>,
      std::shared_ptr<Player>, std::unique_ptr<Ball>);
    std::pair<std::string, std::string> getPlayerNames() const override;
  };
}

#endif // !GAMEMODE1V1_HPP
