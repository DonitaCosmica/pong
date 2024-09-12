#ifndef GAME_HPP
#define GAME_HPP

#include "GameMode.hpp"
#include "../Enums/GameState.hpp"
#include "../Managers/InputManager.hpp"
#include "../Managers/UIManager.hpp"
#include <memory>

namespace pong {
  class Game {
  public:
    Game() = delete;
    Game(Game &&) = delete;
    Game(const Game &) = delete;
    Game &operator=(Game &&) = delete;
    Game &operator=(const Game &) = delete;
    ~Game() = default;

    class Builder;
    void run();

  private:
    Game(UIManager*, InputManager*, GameMode*);
    GameState state;

    UIManager *uiManager;
    InputManager *inputManager;
    GameMode *gameMode;

    void initializeGame();
  };
}

#endif // !GAME_HPP
