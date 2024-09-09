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

    GameMode2v1(std::unique_ptr<Board>, std::unique_ptr<Score>,
      std::shared_ptr<Player>, std::shared_ptr<Player>, std::shared_ptr<Player>,
      std::unique_ptr<Ball>);

    std::pair<std::string, std::string> getPlayerNames() const override;

  private:
    std::shared_ptr<Player> player3;
  };
}

#endif // !GAMEMODE2V1_HPP
