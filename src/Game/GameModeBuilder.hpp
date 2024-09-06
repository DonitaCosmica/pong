#ifndef GAMEMODEBUILDER_HPP
#define GAMEMODEBUILDER_HPP

namespace pong {
  class GameModeBuilder {
  public:
    GameModeBuilder() = default;
    GameModeBuilder(GameModeBuilder &&) = default;
    GameModeBuilder(const GameModeBuilder &) = default;
    GameModeBuilder &operator=(GameModeBuilder &&) = default;
    GameModeBuilder &operator=(const GameModeBuilder &) = default;
    ~GameModeBuilder() = default;

  private:
    
  };
}

#endif // !GAMEMODEBUILDER_HPP 
