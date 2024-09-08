#ifndef GAMEMODE_HPP
#define GAMEMODE_HPP

#include <memory>

namespace pong {
  class GameMode {
  public:
    GameMode() = default;
    GameMode(GameMode &&) = default;
    GameMode(const GameMode &) = default;
    GameMode &operator=(GameMode &&) = default;
    GameMode &operator=(const GameMode &) = default;
    virtual ~GameMode() = default;

    enum class Mode {
      ONE_ONE,
      TWO_ONE
    };

    Mode getMode() const;
    virtual void initializeGame() = 0;

  protected:
    Mode mode;
  };
}

#endif // !GAMEMODE_HPP
