#ifndef GAME_HPP
#define GAME_HPP

#include "GameMode.hpp"
#include "../Managers/InputManager.hpp"
#include "../Managers/UIManager.hpp"

namespace pong
{
  class Game {
  public:
    Game() = delete;
    Game(Game &&) = delete;
    Game(const Game &) = delete;
    Game &operator=(Game &&) = delete;
    Game &operator=(const Game &) = delete;
    ~Game() = default;

    enum class GameState {
      PLAYING,
      GAME_OVER
    };

    class Builder;
    void run();

  private:
    Game(UIManager*, InputManager*, GameMode*);
    GameState state;

    UIManager *uiManager;
    InputManager *inputManager;
    GameMode *gameMode;
  };
}

#endif // !GAME_HPP
