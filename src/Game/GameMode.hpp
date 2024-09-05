#ifndef GAMEMODE_HPP
#define GAMEMODE_HPP

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

    virtual void initializeGame() = 0;

  private:
    
  };
}

#endif // !GAMEMODE_HPP
